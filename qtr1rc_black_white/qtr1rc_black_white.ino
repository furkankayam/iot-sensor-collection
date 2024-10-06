#define sensorPin 8 // Dijital sensör için pin tanımı
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
  int value = digitalRead(sensorPin);

  Serial.print("LED: ");
  Serial.println(value);

  // Dijital değer kontrolü
  if (value == 1) {
    digitalWrite(ledPin, HIGH); // LED'i söndür
  } else {
    digitalWrite(ledPin, LOW); // LED'i yak
  }
}
