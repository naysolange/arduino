#define PIN_BOTON1 A0
#define PIN_BOTON2 A1
#define PIN_LED 9

void setup() {
  pinMode(PIN_BOTON1, INPUT_PULLUP);
  pinMode(PIN_BOTON2, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {

  boolean estadoActualBoton1 = digitalRead(PIN_BOTON1);
  boolean estadoActualBoton2 = digitalRead(PIN_BOTON2);
  boolean elBoton1fuePresionado = estadoActualBoton1 == false;
  boolean elBoton2fuePresionado = estadoActualBoton2 == false;
 
  if(elBoton1fuePresionado) {
    digitalWrite(PIN_LED, HIGH);
    delay(50); 
  } 
  
  if(elBoton2fuePresionado) {
    digitalWrite(PIN_LED, LOW);
    delay(50);
  }

}
