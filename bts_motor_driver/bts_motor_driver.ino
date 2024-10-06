const int RPWM = 10;   // Sağ PWM pini
const int LPWM = 9;    // Sol PWM pini
const int LED = 13;

void setup() {
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  pinMode(LED, OUTPUT);

  // Motoru durdur
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
}

void loop() {
  // Motor hızını yavaş yavaş arttır
  for (int speed = 50; speed <= 255; speed++) {
    digitalWrite(LED, HIGH);
    analogWrite(RPWM, speed);  // RPWM üzerinden hız kontrolü
    analogWrite(LPWM, 0);      // Diğer yön kapalı
    delay(50);                 // Hızın yavaş yavaş artmasını sağlar
  }

  delay(1000); 

  // Motor hızını yavaş yavaş azalt
  for (int speed1 = 255; speed1 >= 50; speed1--) {
    digitalWrite(LED, LOW);
    analogWrite(RPWM, 0);
    analogWrite(LPWM, speed1);
    delay(50);
  }

  delay(1000);  // Maksimum hızda 1 saniye bekle
}