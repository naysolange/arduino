#define PIN_LED1 9
#define UN_SEGUNDO 1000

void setup() {
  pinMode(PIN_LED1, OUTPUT);
}

int cresta = 0;
int valle = 0;

void loop() {

  digitalWrite(PIN_LED1, HIGH);
  cresta = random(0, UN_SEGUNDO);
  delay(cresta);
  
  digitalWrite(PIN_LED1, LOW);
  valle = UN_SEGUNDO - cresta;
  delay(valle);
  
}
