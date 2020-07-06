#define PIN_LED1 9
#define PIN_LED2 10

void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
}

void loop() {

  if(random(0, 2) == 0) {
    digitalWrite(PIN_LED1, HIGH);
  } else {
    digitalWrite(PIN_LED2, HIGH);
  }
 
  delay(250);

  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, LOW);
  
}
