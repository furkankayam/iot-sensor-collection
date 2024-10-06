#include <QTRSensors.h> // QTR v4.0

#define sensorPin 8 // Tek sensör için pin tanımı
#define ledPin 7

QTRSensors qtr; // qtr nesnesi
uint16_t sensorValue; // uint16_t tipi ile değişken tanımlama

void setup() {
  qtr.setTypeRC(); // QTR-8RC ayarı
  qtr.setSensorPins((const uint8_t[]) { sensorPin }, 1); // Tek sensör için pin ayarı
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600); // Seri haberleşmeyi başlat
  delay(1000); // Araca enerji verince 1sn bekle
}

void loop() {
  sensorOku();
  delay(100); // Okuma sıklığını ayarlamak için gecikme
}

void sensorOku() {
  uint16_t sensorValues[1]; // Sensör değerlerini tutacak dizi
  qtr.read(sensorValues); // Sensör değerini oku
  sensorValue = sensorValues[0]; // İlk elemanı al
  Serial.println(sensorValue); // Sensör değerini seri monitöre yazdır
  if (sensorValue >= 1000) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
