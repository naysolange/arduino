#define PIN_BOTON A0
#define PIN_LED1 3
#define PIN_LED2 9

void setup() {
  pinMode(PIN_BOTON, INPUT_PULLUP);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
}

boolean gane = false;
int dado1, dado2;

void loop() {

  boolean estadoActualBoton = digitalRead(PIN_BOTON);
  boolean elBotonEstaPresionado = estadoActualBoton == false;
  boolean tiroDados = !gane && !elBotonEstaPresionado;

  if(tiroDados) {
    dado1 = random(0,2);
    dado2 = random(0,2);
  }

  gane = dado1 == 1 && dado2 == 1 && elBotonEstaPresionado;
  
  if(gane && elBotonEstaPresionado) {
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    delay(50);
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    delay(50);
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    
  } else if(!gane && elBotonEstaPresionado){
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    
  } else {
    digitalWrite(PIN_LED1, dado1);
    digitalWrite(PIN_LED2, dado2);
    delay(50);
  }
  
 
}
