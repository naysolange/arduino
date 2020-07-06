#define PIN_LED1 9
#define PIN_LED2 10
#define UN_SEGUNDO 1000


void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
}

int cresta = 0;
int valle = 0;

void loop() {

  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, LOW);
  cresta = random(0, UN_SEGUNDO);
  valle = UN_SEGUNDO - cresta;
  delay(valle);

  digitalWrite(PIN_LED2, HIGH);
  delay(cresta);

  digitalWrite(PIN_LED1, HIGH);
  digitalWrite(PIN_LED2, LOW);
  delay(valle);

  digitalWrite(PIN_LED2, HIGH);
  delay(cresta);

}
