#define PIN_LED 9
#define UN_SEGUNDO 1000

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {

  digitalWrite(PIN_LED, HIGH);
  delay(UN_SEGUNDO/2);
  digitalWrite(PIN_LED, LOW);
  delay(UN_SEGUNDO/2);

}
