#define PIN_BOTON A0
#define PIN_POTE A1

long valorPote;
int encabezado = 255;
int cierre = 254;
 
void setup() {
  Serial.begin(9600); 
  pinMode(PIN_BOTON, INPUT_PULLUP);
}
 
void loop() {
  
  // leemos del potenciometro
  valorPote = analogRead(A1);
  
  // Acá como solo puedo mandar 1 byte que es un valor hasta 255, mapeo los valores del pote
  // que van desde 0 a 1023 para que vayan de 0 a 252
  valorPote = map(valorPote, 0, 1023, 0, 253);

  boolean estadoActualBoton = digitalRead(PIN_BOTON);
  boolean elBotonfuePresionado = estadoActualBoton == false;
  
  if(elBotonfuePresionado) {
     // Acá le mando a processing el valor del pote entre un encabezado (255) y un valor de cierre (254)
    // (por eso en el map de arriba le mando como valor máximo 253)
    Serial.write(encabezado);
    Serial.write(valorPote);
    Serial.write(cierre);
    delay(100);
  } 
  

}
 
