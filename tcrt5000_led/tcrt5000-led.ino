#define sensorPin 8
//#define ledPin 13
#define buzzerPin 13
#define sensorPinA A0

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(sensorPinA, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(sensorPin);
  int sensorValueA = analogRead(sensorValueA);
  
  if (sensorValue == HIGH) {
    digitalWrite(buzzerPin, HIGH);
    Serial.println(String(1) + " " + sensorValueA);
  } else {
    digitalWrite(buzzerPin, LOW);
    Serial.println(String(0) + " " + sensorValueA);
  }
  
  delay(100);
}
