#define PIN_MOTOR 3

void setup() {
  pinMode(PIN_MOTOR, OUTPUT);
}

void loop() {
  
  analogWrite(PIN_MOTOR, 255);
  


}
