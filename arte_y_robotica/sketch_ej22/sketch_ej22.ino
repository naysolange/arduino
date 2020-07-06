#define PIN_BOTON A0
#define PIN_LED 9

void setup() {
  pinMode(PIN_BOTON, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {

  boolean estadoActualBoton = digitalRead(PIN_BOTON);
  boolean elBotonfuePresionado = estadoActualBoton == false;
  
  if(elBotonfuePresionado) {
    digitalWrite(PIN_LED, HIGH);
    delay(50); 
  } 
  
}
