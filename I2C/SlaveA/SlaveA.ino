#include <Wire.h>

const int isReadyBtn = 2;
const int isActive = 4;
const int isReceive = 8;

int isReadyState = 1;
bool isReady = true;

byte data[2];
int result;

void setup() {
  Serial.begin(9600);
  Wire.begin(9);
  Wire.onReceive(getEvent);
  pinMode(isReadyBtn, INPUT);
  pinMode(isActive, OUTPUT);
  pinMode(isReceive, OUTPUT);
}

void loop() {
  isReadyState = digitalRead(isReadyBtn);
  
  if (isReadyState == LOW) {
    isReady = !isReady;
  }
  
  if (isReady == 1){
    digitalWrite(isActive, HIGH);
  } else {
    digitalWrite(isActive, LOW);
  }
  
  delay(250);
}

void getEvent() {
  while (Wire.available()) {
    for (int i=0;i<2;i++) {
      data[i] = Wire.read();
    }

    // 2 bytes to int
    result = data[0];
    result = (result<<8) | data[1];
    
    digitalWrite(isReceive, HIGH);
    delay(250);
    digitalWrite(isReceive, LOW);
    delay(250);
    
    Serial.println(result);
  }
}
