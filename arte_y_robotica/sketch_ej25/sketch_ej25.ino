#define PIN_BOTON A0
#define PIN_LED 9

boolean estadoAnteriorBoton = true;

void setup() {
  pinMode(PIN_BOTON, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {

  boolean estadoActualBoton = digitalRead(PIN_BOTON);
  boolean elBotonfuePresionado = estadoActualBoton == false;
  boolean suEstadoEsIgualAlAnterior = estadoActualBoton == estadoAnteriorBoton;
 
  if(elBotonfuePresionado && suEstadoEsIgualAlAnterior) {
    digitalWrite(PIN_LED, random(0,2));
    delay(50); 
  } 

  estadoAnteriorBoton = estadoActualBoton;
  digitalWrite(PIN_LED, LOW);
}
