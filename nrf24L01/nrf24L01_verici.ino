#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define button 5

RF24 radio(9, 8);
const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening();
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  static unsigned long lastPress = 0; // Son buton basma zamanı
  static int pressCount = 0; // Buton basma sayacı

  // Buton durumu kontrolü
  if (digitalRead(button) == LOW) {
    // Eğer butona basıldıysa
    if (millis() - lastPress > 500) { // Debounce
      pressCount++;
      lastPress = millis(); // Son basma zamanını güncelle
      Serial.print("Butona basıldı, toplam basım: ");
      Serial.println(pressCount); // Seri portta basım sayısını yazdır
    }
  } else {
    // Buton bırakıldıysa
    if (pressCount > 0) {
      char text[2]; // Gönderilecek metin
      if (pressCount == 1) {
        text[0] = '1'; // Tek basımda '1' gönder
        Serial.println("Gönderilen: 1"); // Seri portta gönderilen değeri yazdır
      } else if (pressCount >= 2) {
        text[0] = '0'; // İki basımda '0' gönder
        Serial.println("Gönderilen: 0"); // Seri portta gönderilen değeri yazdır
      }
      text[1] = '\0'; // String sonlandırıcı
      radio.write(&text, sizeof(text)); // Veriyi gönder
      pressCount = 0; // Sayacı sıfırla
    }
  }
  
  delay(50); // Döngü hızını kontrol et
}
