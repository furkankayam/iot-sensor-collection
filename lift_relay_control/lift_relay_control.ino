int relay1Pin = 2;
int relay2Pin = 3;
int switchPin1 = 8;
int switchPin2 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);

  digitalWrite(relay1Pin, HIGH);
  digitalWrite(relay2Pin, HIGH);
}

void loop() {
  int switchState1 = digitalRead(switchPin1);
  int switchState2 = digitalRead(switchPin2);

  if (switchState1 == HIGH) {
    //UP
    Serial.println("Yukarı Hareket");
    digitalWrite(relay1Pin, LOW);
    digitalWrite(relay2Pin, LOW);
  } else if (switchState2 == HIGH) {
    //DOWN
    Serial.println("Aşağı Hareket");
    digitalWrite(relay1Pin, HIGH);
    digitalWrite(relay2Pin, HIGH);
  } else {
    // Her iki switch de kapalıysa röleleri kapalı tut
    Serial.println("Dur");
    digitalWrite(relay1Pin, HIGH);
    digitalWrite(relay2Pin, HIGH);
  }

  delay(500);
}
