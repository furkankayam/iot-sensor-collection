#include <Arduino.h>

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 2
#define ledPin 13

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(ledPin, OUTPUT);

  // TCS3200 için frekansı %2 ölçeklendirin
  digitalWrite(S0, LOW);
  digitalWrite(S1, HIGH); // %2 frekans ayarı

  Serial.begin(9600);
}

void loop() {
  int sensorValue;

  // Kırmızı ölçüm
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  sensorValue = pulseIn(sensorOut, LOW);

  // Siyah veya beyaz algılama
  if (sensorValue > 1200) {
    // Siyah yüzey algılandı
    digitalWrite(ledPin, HIGH); // LED'i yak
  } else {
    // Beyaz yüzey algılandı
    digitalWrite(ledPin, LOW); // LED'i söndür
  }

  // Debug için seri monitöre yazdır
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  delay(100); // Döngüde gecikme
}
