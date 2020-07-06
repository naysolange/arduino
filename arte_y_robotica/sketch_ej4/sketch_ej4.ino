#define PIN_LED1 9
#define PIN_LED2 10
#define PIN_LED3 11
#define MEDIO_SEGUNDO 500

void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
}

void loop() {

  // Primer led
  digitalWrite(PIN_LED1, HIGH);
  delay(MEDIO_SEGUNDO);
  digitalWrite(PIN_LED1, LOW);

  // Segundo led
  digitalWrite(PIN_LED2, HIGH);
  delay(MEDIO_SEGUNDO);
  digitalWrite(PIN_LED2, LOW);

  // Tercer led
  digitalWrite(PIN_LED3, HIGH);
  delay(MEDIO_SEGUNDO);
  digitalWrite(PIN_LED3, LOW);

}
