#define PIN_LED0 9
#define PIN_LED1 10
#define PIN_LED2 11

void setup() {
  pinMode(PIN_LED0, OUTPUT);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
}

int combinaciones[6][3] = { {PIN_LED0, PIN_LED1, PIN_LED2}, {PIN_LED0, PIN_LED2, PIN_LED1}, {PIN_LED1, PIN_LED0, PIN_LED2}, {PIN_LED1, PIN_LED2, PIN_LED0}, {PIN_LED2, PIN_LED0, PIN_LED1}, {PIN_LED2, PIN_LED1, PIN_LED0} };

void loop() {


  for(int i=0; i<6; i++) {
    
    for(int j=0; j<3; j++) {
      int ledAPrender = combinaciones[i][j];
      digitalWrite(ledAPrender, HIGH);
      delay(250); 
    }
    
    digitalWrite(PIN_LED0, LOW);
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    delay(500);
  }
 
}
