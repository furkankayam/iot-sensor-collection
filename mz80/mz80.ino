int ledPin = 13;
int inputPin = 7;
int val = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
}

void loop(){
  val = digitalRead(inputPin);
  if (val == HIGH) {
    digitalWrite(ledPin, LOW);
    Serial.println("Cisim yok!");
  } else {
    digitalWrite(ledPin, HIGH);
    Serial.println("Cisim var!");
  }
  delay(100);
}