#define PIN_LED1 9
#define PIN_LED2 10

#define MEDIO_SEGUNDO 500

void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);

}

void loop() {

  // Primer led
  digitalWrite(PIN_LED1, HIGH);
  digitalWrite(PIN_LED2, LOW);
  delay(MEDIO_SEGUNDO);
  

  // Segundo led
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, HIGH);
  delay(MEDIO_SEGUNDO);

}
