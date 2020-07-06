#define PIN_LED1 9
#define DOS_SEGUNDOS 2000

void setup() {
  pinMode(PIN_LED1, OUTPUT);
}

float periodo = 0; 

void loop() {

  periodo = random(0, DOS_SEGUNDOS);
  digitalWrite(PIN_LED1, HIGH);
  delay(periodo/2);
  digitalWrite(PIN_LED1, LOW);
  delay(periodo/2);
  
}
