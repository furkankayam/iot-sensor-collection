// Pin tanımları
const int RPWM_Pin = 5;   // RPWM pin
const int LPWM_Pin = 6;   // LPWM pin
const int R_EN_Pin = 7;   // R_EN pin
const int L_EN_Pin = 8;   // L_EN pin

// Değişkenler
int motorSpeed = 0;      // Motor hızı başlangıçta sıfır
int speedIncrement = 10; // Hız artış miktarı

void setup() {
  // Pin modlarını ayarlıyoruz
  pinMode(RPWM_Pin, OUTPUT);
  pinMode(LPWM_Pin, OUTPUT);
  pinMode(R_EN_Pin, OUTPUT);
  pinMode(L_EN_Pin, OUTPUT);
  
  // Başlangıçta motor kapalı, enable pinlerini aktif ediyoruz
  digitalWrite(R_EN_Pin, HIGH);  // Sağ kanal aktif
  digitalWrite(L_EN_Pin, HIGH);  // Sol kanal aktif
}

void loop() {
  // Motor hızını artırarak ileri yönde hareket ettir
  for (motorSpeed = 0; motorSpeed <= 255; motorSpeed += speedIncrement) {
    analogWrite(RPWM_Pin, motorSpeed);  // İleri hareket için RPWM kullanılır
    analogWrite(LPWM_Pin, 0);           // Geri hareket kapalı
    delay(100);  // Hızı yavaş yavaş artır
  }

  delay(2000);  // Motor maksimum hızda 2 saniye çalışsın

  // Motoru durdur
  analogWrite(RPWM_Pin, 0);
  analogWrite(LPWM_Pin, 0);
  delay(1000);

  // Ters yönde hızını azaltarak hareket ettir
  for (motorSpeed = 255; motorSpeed >= 0; motorSpeed -= speedIncrement) {
    analogWrite(LPWM_Pin, motorSpeed);  // Geriye hareket için LPWM kullanılır
    analogWrite(RPWM_Pin, 0);           // İleri hareket kapalı
    delay(100);  // Hızı yavaş yavaş azalt
  }

  delay(2000);  // Motor tamamen durduktan sonra 2 saniye bekle
}