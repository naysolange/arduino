#define PIN_LED1 9


void setup() {
  pinMode(PIN_LED1, OUTPUT);
}

int cresta = 10;

void loop() {

    if(cresta >= 200) {
      cresta = 10;
    }

    digitalWrite(PIN_LED1, HIGH);
    delay(cresta);
    digitalWrite(PIN_LED1, LOW);
    delay(10);
    
    cresta = cresta + 10;
    
}
