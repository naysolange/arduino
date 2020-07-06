#define PIN_LED 9
#define UN_SEGUNDO 1000

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  
  digitalWrite(PIN_LED, HIGH);
  delay((2/3)*UN_SEGUNDO);
  digitalWrite(PIN_LED, LOW);
  delay((1/3)*UN_SEGUNDO);

}
