#define PIN_LED1 9
#define PIN_LED2 10

void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
}

bool encenderPrimerLed, encenderSegundoLed;

void loop() {

  encenderPrimerLed = random(0, 2) == 0;
  
  if(encenderPrimerLed) {
    digitalWrite(PIN_LED1, HIGH);

    encenderSegundoLed = random(0, 2) == 0;
    if(encenderSegundoLed) {
      digitalWrite(PIN_LED2, HIGH);
    }
  } else {
    encenderSegundoLed = random(0, 2) == 0;
    if(encenderSegundoLed) {
      digitalWrite(PIN_LED2, HIGH);
    } 
  }

  delay(250);
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, LOW);
  
 
  
}
