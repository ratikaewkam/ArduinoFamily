#define is_ready_btn 2
#define is_active 4

int is_ready_state = 1;
bool is_ready = true;

void setup() {
  Serial.begin(9600);
  pinMode(is_ready_btn, INPUT);
  pinMode(is_active, OUTPUT);
}

void loop() {
  is_ready_state = digitalRead(is_ready_btn);
  int poten = analogRead(A0);

  if (is_ready){
    digitalWrite(is_active, HIGH);
  } else {
    digitalWrite(is_active, LOW);
  }
  
  if (is_ready_state == LOW) {
    is_ready = !is_ready;
  }
  
  delay(250);
}
