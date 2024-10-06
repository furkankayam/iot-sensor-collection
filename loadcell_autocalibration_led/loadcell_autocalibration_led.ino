#include <HX711_ADC.h>
#if defined(ESP8266)|| defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#endif

// Pins
const int HX711_dout = 4; // MCU > HX711 dout pin
const int HX711_sck = 5; // MCU > HX711 sck pin
const int ledPin = 13; // LED için pin

// HX711 constructor
HX711_ADC LoadCell(HX711_dout, HX711_sck);

const int calVal_eepromAdress = 0;
unsigned long t = 0;

void setup() {
  Serial.begin(57600); delay(10);
  Serial.println();
  Serial.println("Starting...");

  pinMode(ledPin, OUTPUT); // LED pinini çıkış olarak ayarla
  LoadCell.begin();
  unsigned long stabilizingtime = 2000; // Stabilizasyon süresi
  boolean _tare = true; // Tare işlemi yapılacak
  LoadCell.start(stabilizingtime, _tare);
  
  if (LoadCell.getTareTimeoutFlag() || LoadCell.getSignalTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  } else {
    // EEPROM'dan kalibrasyon değerini oku
    float calFactor;
    EEPROM.get(calVal_eepromAdress, calFactor);
    LoadCell.setCalFactor(calFactor); // EEPROM'dan okunan kalibrasyon değerini ayarla
    Serial.println("Startup is complete");
  }
  
  while (!LoadCell.update());
}

void loop() {
  static boolean newDataReady = 0;
  const int serialPrintInterval = 0; // Seri yazdırma aralığı

  // Yeni verileri kontrol et:
  if (LoadCell.update()) newDataReady = true;

  // Veri kümesinden ortalama değeri al:
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell.getData();
      Serial.print("Load_cell output val: ");
      Serial.println(i);

      // Eğer ölçüm 1 kg ise, LED'ı aç
      if (i >= 1000.0) { // 1 kg = 1000 gram
        digitalWrite(ledPin, HIGH); // LED'ı aç
      } else {
        digitalWrite(ledPin, LOW); // LED'ı kapat
      }

      newDataReady = 0;
      t = millis();
    }
  }

  // Seri terminalden komut al
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell.tareNoDelay(); // tare
    else if (inByte == 'c') changeSavedCalFactor(); // Kalibrasyon değerini manuel değiştir
  }

  // Son tare işleminin tamamlanıp tamamlanmadığını kontrol et
  if (LoadCell.getTareStatus() == true) {
    Serial.println("Tare complete");
  }
}

void changeSavedCalFactor() {
  float oldCalibrationValue = LoadCell.getCalFactor();
  boolean _resume = false;
  Serial.println("***");
  Serial.print("Current value is: ");
  Serial.println(oldCalibrationValue);
  Serial.println("Now, send the new value from serial monitor, i.e. 696.0");
  
  float newCalibrationValue;
  while (_resume == false) {
    if (Serial.available() > 0) {
      newCalibrationValue = Serial.parseFloat();
      if (newCalibrationValue != 0) {
        Serial.print("New calibration value is: ");
        Serial.println(newCalibrationValue);
        LoadCell.setCalFactor(newCalibrationValue);
        _resume = true;
      }
    }
  }
  
  _resume = false;
  Serial.print("Save this value to EEPROM address ");
  Serial.print(calVal_eepromAdress);
  Serial.println("? y/n");
  
  while (_resume == false) {
    if (Serial.available() > 0) {
      char inByte = Serial.read();
      if (inByte == 'y') {
#if defined(ESP8266)|| defined(ESP32)
        EEPROM.begin(512);
#endif
        EEPROM.put(calVal_eepromAdress, newCalibrationValue);
#if defined(ESP8266)|| defined(ESP32)
        EEPROM.commit();
#endif
        Serial.print("Value ");
        Serial.print(newCalibrationValue);
        Serial.print(" saved to EEPROM address: ");
        Serial.println(calVal_eepromAdress);
        _resume = true;
      } else if (inByte == 'n') {
        Serial.println("Value not saved to EEPROM");
        _resume = true;
      }
    }
  }
  
  Serial.println("End change calibration value");
  Serial.println("***");
}
