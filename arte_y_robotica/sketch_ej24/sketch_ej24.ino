#define PIN_BOTON A0
#define PIN_LED 9

boolean estadoLed = false;
boolean estadoAnteriorBoton = true;


void setup() {
  pinMode(PIN_BOTON, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {

  boolean estadoActualBoton = digitalRead(PIN_BOTON);
  boolean elBotonfuePresionado = estadoActualBoton == false;
  boolean suEstadoEsDistintoAlAnterior = estadoActualBoton != estadoAnteriorBoton;
 
  if(elBotonfuePresionado && suEstadoEsDistintoAlAnterior) {
    estadoLed = !estadoLed; // Cambio estado del led
    delay(50); // Anti rebote - por los errores mecanicos de los botones
  } 

  estadoAnteriorBoton = estadoActualBoton;
  digitalWrite(PIN_LED, estadoLed);//salida del led
}
