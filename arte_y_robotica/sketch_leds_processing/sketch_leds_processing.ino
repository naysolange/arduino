
#define PIN_ROJO 6
#define PIN_VERDE 5
#define PIN_AZUL 3

boolean esperaColor = false;
int cantidad = 0;
byte rojo = 0, verde = 0, azul = 0;
byte dato;
byte header = 127;

void setup() {
  Serial.begin(9600); 
  pinMode(PIN_ROJO, OUTPUT);
  pinMode(PIN_VERDE, OUTPUT);
  pinMode(PIN_AZUL, OUTPUT);
}

void loop() {

  analogWrite(PIN_ROJO, 0);
  analogWrite(PIN_VERDE, 0);
  analogWrite(PIN_AZUL, 0);

  if(Serial.available() > 0) {
    
    dato = Serial.read();
    
    if(dato == header) {
      esperaColor = true;
    }  
  }

  if(esperaColor) {
    if(cantidad == 0){
      //dato = 116;
     //Serial.println(dato);
      if(dato == 116) {
        analogWrite(PIN_ROJO, 255);
       delay(100);
       analogWrite(PIN_ROJO, 0);
      }
      rojo = map(dato, 0, 126, 0, 255);
      cantidad++;
    } else if(cantidad == 1){
      dato = 10;
      verde = map(dato, 0, 126, 0, 255);
      cantidad++;
    } else if(cantidad == 2){
      dato = 12;
      azul = map(dato, 0, 126, 0, 255);
      cantidad = 0;
      esperaColor = false;
    }
  } else {
    analogWrite(PIN_ROJO, 0);
    analogWrite(PIN_VERDE, 0);
    analogWrite(PIN_AZUL, 0);
    analogWrite(PIN_ROJO, rojo);
  //  analogWrite(PIN_VERDE, verde);
  //  analogWrite(PIN_AZUL, azul);
    delay(1000);
  }
  
  /*analogWrite(PIN_ROJO, 234);
  analogWrite(PIN_VERDE, 23);
  analogWrite(PIN_AZUL, 29);*/

}
