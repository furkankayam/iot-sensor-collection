#define role 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(role, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(role, HIGH);
  delay(3000); 
  digitalWrite(role, LOW);
  delay(3000);

}
