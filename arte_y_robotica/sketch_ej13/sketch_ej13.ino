#define PIN_LED0 9
#define PIN_LED1 10
#define PIN_LED2 11

void setup() {
  pinMode(PIN_LED0, OUTPUT);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
}

void loop() {

  int a = random(0, 6);
  int b = random(0, 6);

  if(a > b){
     digitalWrite(PIN_LED0, HIGH);
  } else if(a < b) {
     digitalWrite(PIN_LED1, HIGH);
  } else {
     digitalWrite(PIN_LED2, HIGH);
  }

  delay(250);
  digitalWrite(PIN_LED0, LOW);
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, LOW);
  
}
