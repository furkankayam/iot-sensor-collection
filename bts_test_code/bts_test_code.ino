// LEFT BTS
#define RPWM1_Pin 5
#define LPWM1_Pin 6

void setup() {
  Serial.begin(9600);
  pinMode(RPWM1_Pin, OUTPUT);
  pinMode(LPWM1_Pin, OUTPUT);
}

void loop() {
  forward();
  delay(3000);
  backward();
  delay(3000);
}

void forward() {
  for (int pwmValue = 55; pwmValue <= 255; pwmValue += 20) {
    analogWrite(RPWM1_Pin, 0);
    analogWrite(LPWM1_Pin, pwmValue);
    Serial.print("forward: ");
    Serial.println(pwmValue);
    delay(100);
  }
}

void backward() {
  for (int pwmValue = 55; pwmValue <= 255; pwmValue += 20) {
    analogWrite(RPWM1_Pin, pwmValue);
    analogWrite(LPWM1_Pin, 0);
    Serial.print("backward: ");
    Serial.println(pwmValue);
    delay(100);
  }
}

void stop() {
  analogWrite(RPWM1_Pin, 0);
  analogWrite(LPWM1_Pin, 0);
  Serial.println("stop");
}
