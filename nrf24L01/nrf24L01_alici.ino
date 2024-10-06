#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define ledPin 5 // LED için pin tanımı

RF24 radio(9, 8);
const byte address[6] = "00001";

bool ledState = LOW; // LED durumu

void setup() {
  while (!Serial); // Seri portun açılmasını bekle
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, address); // Okuma borusunu aç
  radio.startListening();
  pinMode(ledPin, OUTPUT); // LED pinini çıkış olarak ayarla
}

void loop() {
  if (radio.available()) {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text); // Gelen veriyi seri portta göster

    // Gelen veriye göre LED'i kontrol et
    if (text[0] == '1') {
      ledState = HIGH; // '1' geldiğinde LED'i aç
      digitalWrite(ledPin, ledState);
      Serial.println("LED ON");
    } else if (text[0] == '0') {
      ledState = LOW; // '0' geldiğinde LED'i kapat
      digitalWrite(ledPin, ledState);
      Serial.println("LED OFF");
    }
  }

  // LED'in durumu 'HIGH' olduğunda yanmaya devam et
  if (ledState == HIGH) {
    digitalWrite(ledPin, HIGH); // LED'i açık tut
  }
}
