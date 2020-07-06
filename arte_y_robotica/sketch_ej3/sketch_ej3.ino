#define PIN_LED 9
#define UN_SEGUNDO 1000
#define DOS_SEGUNDOS 2000
#define MEDIO_SEGUNDO 500

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {

  // Primer período
  digitalWrite(PIN_LED, HIGH);
  delay(UN_SEGUNDO/2);
  digitalWrite(PIN_LED, LOW);
  delay(UN_SEGUNDO/2);

  // Segundo período
  digitalWrite(PIN_LED, HIGH);
  delay((2/3)*DOS_SEGUNDOS);
  digitalWrite(PIN_LED, LOW);
  delay((1/3)*DOS_SEGUNDOS);

  // Tercer período
  digitalWrite(PIN_LED, HIGH);
  delay((1/3)*MEDIO_SEGUNDO);
  digitalWrite(PIN_LED, LOW);
  delay((2/3)*MEDIO_SEGUNDO);

}
