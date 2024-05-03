void setup() {
  Serial.begin(9600);
}

void loop() {
  int poten = analogRead(A0);
  Serial.println(poten);
  delay(1500);
}
