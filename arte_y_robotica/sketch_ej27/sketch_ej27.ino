#define PIN_BOTON1 A0
#define PIN_BOTON2 A1
#define PIN_LED 9
#define PERIODO_MINIMO 10
#define PERIODO_MAXIMO 100

int periodo = PERIODO_MINIMO;

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
    periodo++;
    if(periodo > PERIODO_MAXIMO) {
      periodo = PERIODO_MINIMO;
    }
  }

  if(elBoton2fuePresionado) {
    periodo--;
    if(periodo < PERIODO_MINIMO) {
      periodo = PERIODO_MINIMO;
    }
  }
  
  digitalWrite(PIN_LED, HIGH);
  delay(periodo/2); 
  digitalWrite(PIN_LED, LOW);
  delay(periodo/2);

}
