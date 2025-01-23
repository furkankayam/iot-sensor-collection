// LEFT BTS
#define RPWM1_Pin 5
#define LPWM1_Pin 6

// SPEED
//int speed = 250;
int speed = 100;

void setup() {
  Serial.begin(9600);
  pinMode(RPWM1_Pin, OUTPUT);
  pinMode(LPWM1_Pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward(speed);
  delay(1000);
  backward(speed);
  delay(1000);
  stop();
  delay(1000);
}

void backward(int speed) {
  analogWrite(RPWM1_Pin, speed);
  analogWrite(LPWM1_Pin, 0);
  Serial.println("backward");
}

void forward(int speed) {
  analogWrite(RPWM1_Pin, 0);
  analogWrite(LPWM1_Pin, speed);
  Serial.println("forward");
}

void stop() {
  analogWrite(RPWM1_Pin, 0);
  analogWrite(LPWM1_Pin, 0);
  Serial.println("stop");
}