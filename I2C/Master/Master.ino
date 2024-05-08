#include <Wire.h> 

const int isReadyBtn = 2;
const int isActive = 4;
const int isReceive = 8;

#define SLAVE_A_ADDR 0x09 // Slave Address

int isReadyState = 1;
bool isReady = true;

byte data[2];

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(isReadyBtn, INPUT);
  pinMode(isActive, OUTPUT);
  pinMode(isReceive, OUTPUT);
}

void loop() {
  isReadyState = digitalRead(isReadyBtn);
  int poten = analogRead(A0);

  if (isReadyState == LOW) {
    isReady = !isReady;
  }
  
  if (isReady){
    digitalWrite(isActive, HIGH);
    Wire.beginTransmission(SLAVE_A_ADDR);

    // Sending 2 bytes (int)
    data[0] = poten >> 8;
    data[1] = poten & 0xFF;
    Wire.write(data, 2);
    Wire.endTransmission();
    Serial.println(poten);   
  } else {
    digitalWrite(isActive, LOW);
  }
  
  delay(250);
}
