#define sensorPin A0 // Analog sensör için pin tanımı (A0)
#define ledPin 13

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600); // Seri haberleşmeyi başlat
  delay(1000); // Araca enerji verince 1sn bekle
}

void loop() {
  sensorOku(); // Sensör değerini oku
  delay(100); // Okuma sıklığını ayarlamak için gecikme
}

void sensorOku() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue); // Sensör değerini seri monitöre yazdır

  // Analog değer için eşik ayarı
  if (sensorValue >= 550) { // Eşik değeri, sensör çıkışına göre ayarlanabilir
    digitalWrite(ledPin, HIGH); // LED'i yak
  } else {
    digitalWrite(ledPin, LOW); // LED'i söndür
  }
}
