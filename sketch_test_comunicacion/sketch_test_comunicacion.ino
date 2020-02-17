#include <Adafruit_NeoPixel.h>

#define PIN_TIRA_LED 6 
#define CANT_PIXELS 480

Adafruit_NeoPixel matrix(CANT_PIXELS, PIN_TIRA_LED, NEO_GRB + NEO_KHZ800);

int offset = 6;
String PEDIR_TEXTO = "texto";

uint32_t colorTexto = matrix.Color(0, 90, 20);
boolean pedirTexto = true;


void setup() {
  Serial.begin(9600);
  matrix.begin();
}

void loop() {

     matrix.clear();

     mostrarPatronLuminico();

    if(pedirTexto) {
     Serial.println(PEDIR_TEXTO);
     pedirTexto = false;
    }

    if(Serial.available() > 0) {
      char bufer[150];
      int leido = Serial.readBytesUntil('|', bufer, 150);

      char poesia[leido+1];
      for(int i=0; i<leido; i++) {
        poesia[i] = bufer[i];
      }
      poesia[leido+1] = '\0';
      
      scroll(poesia);
    } 
   
  
}

void mostrarPatronLuminico() {

 uint32_t colorLed;

  int led1APrender = random(0,CANT_PIXELS);
  colorLed = obtenerColorRandom();
  matrix.setPixelColor(led1APrender, colorLed);
  matrix.show(); 
     
  int led2APrender = random(0,CANT_PIXELS);
  colorLed = obtenerColorRandom();
  matrix.setPixelColor(led2APrender, colorLed);

  int led3APrender = random(0,CANT_PIXELS);
  colorLed = obtenerColorRandom();
  matrix.setPixelColor(led3APrender, colorLed);

  int led4APrender = random(0,CANT_PIXELS);
  colorLed = obtenerColorRandom();
  matrix.setPixelColor(led4APrender, colorLed);

  int led5APrender = random(0,CANT_PIXELS);
  colorLed = obtenerColorRandom();
  matrix.setPixelColor(led5APrender, colorLed);

  matrix.show(); 
  colorTexto = colorLed;
  delay(200);
  
}

uint32_t obtenerColorRandom() {
  uint32_t colorLed;
  switch(random(1,3)) {
    case 1:
      // Magenta
      colorLed = matrix.Color(random(50,200), 0, random(10,100));
      break;
    case 2:
     // Naranja
      colorLed = matrix.Color(random(200,255), random(50,100), 0);
      break;
  }

  return colorLed;
}


void dibujarA(int offset) {
    prenderPixel(1,2, offset, colorTexto);
    prenderPixel(2,2, offset, colorTexto);
    prenderPixel(3,3, offset, colorTexto);
    prenderPixel(1,4, offset, colorTexto);
    prenderPixel(2,4, offset, colorTexto);
    prenderPixel(3,4, offset, colorTexto);
    prenderPixel(0,5, offset, colorTexto);
    prenderPixel(3,5, offset, colorTexto);
    prenderPixel(1,6, offset, colorTexto);
    prenderPixel(2,6, offset, colorTexto);
    prenderPixel(3,6, offset, colorTexto);
    prenderPixel(4,6, offset, colorTexto);
}

void dibujarAConTilde(int offset) {
    dibujarA(offset);
    prenderPixel(3,0, offset, colorTexto);
    prenderPixel(2,1, offset, colorTexto);
}

void dibujarB(int offset) {
    prenderPixel(0,0, offset, colorTexto);
    prenderPixel(0,1, offset, colorTexto);
    prenderPixel(0,2, offset, colorTexto);
    prenderPixel(0,3, offset, colorTexto);
    prenderPixel(0,4, offset, colorTexto);
    prenderPixel(0,5, offset, colorTexto);
    prenderPixel(0,6, offset, colorTexto);
    prenderPixel(1,3, offset, colorTexto);
    prenderPixel(1,5, offset, colorTexto);
    prenderPixel(2,2, offset, colorTexto);
    prenderPixel(2,6, offset, colorTexto);
    prenderPixel(3,2, offset, colorTexto);
    prenderPixel(3,6, offset, colorTexto);
    prenderPixel(4,3, offset, colorTexto);
    prenderPixel(4,4, offset, colorTexto);
    prenderPixel(4,5, offset, colorTexto);
}

void dibujarC(int offset) {
    prenderPixel(0,3, offset, colorTexto);
    prenderPixel(0,4, offset, colorTexto);
    prenderPixel(0,5, offset, colorTexto);
    prenderPixel(1,2, offset, colorTexto);
    prenderPixel(1,6, offset, colorTexto);
    prenderPixel(2,2, offset, colorTexto);
    prenderPixel(2,6, offset, colorTexto);
    prenderPixel(3,2, offset, colorTexto);
    prenderPixel(3,6, offset, colorTexto);
    prenderPixel(4,3, offset, colorTexto);
    prenderPixel(4,5, offset, colorTexto);
}

void dibujarD(int offset) {
    prenderPixel(0,3, offset, colorTexto);
    prenderPixel(0,4, offset, colorTexto);
    prenderPixel(0,5, offset, colorTexto);
    prenderPixel(1,2, offset, colorTexto);
    prenderPixel(1,6, offset, colorTexto);
    prenderPixel(2,2, offset, colorTexto);
    prenderPixel(2,6, offset, colorTexto);
    prenderPixel(3,3, offset, colorTexto);
    prenderPixel(3,5, offset, colorTexto);
    prenderPixel(4,0, offset, colorTexto);
    prenderPixel(4,1, offset, colorTexto);
    prenderPixel(4,2, offset, colorTexto);
    prenderPixel(4,3, offset, colorTexto);
    prenderPixel(4,4, offset, colorTexto);
    prenderPixel(4,5, offset, colorTexto);
    prenderPixel(4,6, offset, colorTexto);
}

void dibujarE(int offset) {
    prenderPixel(0,3, offset, colorTexto);
    prenderPixel(0,4, offset, colorTexto);
    prenderPixel(0,5, offset, colorTexto);
    prenderPixel(1,2, offset, colorTexto);
    prenderPixel(1,4, offset, colorTexto);
    prenderPixel(1,6, offset, colorTexto);
    prenderPixel(2,2, offset, colorTexto);
    prenderPixel(2,4, offset, colorTexto);
    prenderPixel(2,6, offset, colorTexto);
    prenderPixel(3,2, offset, colorTexto);
    prenderPixel(3,4, offset, colorTexto);
    prenderPixel(3,6, offset, colorTexto);
    prenderPixel(4,3, offset, colorTexto);
    prenderPixel(4,4, offset, colorTexto);
}

void dibujarEConTilde(int offset) {
    dibujarE(offset);
    prenderPixel(3,0, offset, colorTexto);
    prenderPixel(2,1, offset, colorTexto);
}

void dibujarF(int offset) {
    prenderPixel(1,3, offset, colorTexto);
    prenderPixel(2,1, offset, colorTexto);
    prenderPixel(2,2, offset, colorTexto);
    prenderPixel(2,3, offset, colorTexto);
    prenderPixel(2,4, offset, colorTexto);
    prenderPixel(2,5, offset, colorTexto);
    prenderPixel(2,6, offset, colorTexto);
    prenderPixel(3,0, offset, colorTexto);
    prenderPixel(3,3, offset, colorTexto);
    prenderPixel(4,1, offset, colorTexto);
}

void dibujarG(int offset) {
    prenderPixel(0,3, offset, colorTexto);
    prenderPixel(0,4, offset, colorTexto);
    prenderPixel(1,2, offset, colorTexto);
    prenderPixel(1,5, offset, colorTexto);
    prenderPixel(1,7, offset, colorTexto);
    prenderPixel(2,2, offset, colorTexto);
    prenderPixel(2,5, offset, colorTexto);
    prenderPixel(2,7, offset, colorTexto);
    prenderPixel(3,2, offset, colorTexto);
    prenderPixel(3,3, offset, colorTexto);
    prenderPixel(3,4, offset, colorTexto);
    prenderPixel(3,7, offset, colorTexto);
    prenderPixel(4,3, offset, colorTexto);
    prenderPixel(4,4, offset, colorTexto);
    prenderPixel(4,5, offset, colorTexto);
    prenderPixel(4,6, offset, colorTexto);
}

void dibujarH(int offset) {
    prenderPixel(0, 0, offset, colorTexto);
    prenderPixel(0, 1, offset, colorTexto);
    prenderPixel(0, 2, offset, colorTexto);
    prenderPixel(2, 2, offset, colorTexto);
    prenderPixel(3, 2, offset, colorTexto);
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(1, 3, offset, colorTexto);
    prenderPixel(4, 3, offset, colorTexto);
    prenderPixel(0, 4, offset, colorTexto);
    prenderPixel(4, 4, offset, colorTexto);
    prenderPixel(0, 5, offset, colorTexto);
    prenderPixel(4, 5, offset, colorTexto);
    prenderPixel(0, 6, offset, colorTexto);
    prenderPixel(4, 6, offset, colorTexto);
}

void dibujarI(int offset) {
    prenderPixel(1,2, offset, colorTexto);
    prenderPixel(1,6, offset, colorTexto);
    prenderPixel(2,0, offset, colorTexto);
    prenderPixel(2,2, offset, colorTexto);
    prenderPixel(2,3, offset, colorTexto);
    prenderPixel(2,4, offset, colorTexto);
    prenderPixel(2,5, offset, colorTexto);
    prenderPixel(2,6, offset, colorTexto);
    prenderPixel(3,6, offset, colorTexto);
}

void dibujarIConTilde(int offset) {
    prenderPixel(1,2, offset, colorTexto);
    prenderPixel(1,6, offset, colorTexto);
    prenderPixel(2,1, offset, colorTexto);
    prenderPixel(2,2, offset, colorTexto);
    prenderPixel(2,3, offset, colorTexto);
    prenderPixel(2,4, offset, colorTexto);
    prenderPixel(2,5, offset, colorTexto);
    prenderPixel(2,6, offset, colorTexto);
    prenderPixel(3,6, offset, colorTexto);
    prenderPixel(3,0, offset, colorTexto);
}

void dibujarJ(int offset) {
    prenderPixel(0,5, offset, colorTexto);
    prenderPixel(1,6, offset, colorTexto);
    prenderPixel(2,6, offset, colorTexto);
    prenderPixel(3,0, offset, colorTexto);
    prenderPixel(3,2, offset, colorTexto);
    prenderPixel(3,3, offset, colorTexto);
    prenderPixel(3,4, offset, colorTexto);
    prenderPixel(3,5, offset, colorTexto);
}

void dibujarK(int offset) {
    prenderPixel(0, 0, offset, colorTexto);
    prenderPixel(0, 1, offset, colorTexto);
    prenderPixel(0, 2, offset, colorTexto);
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(0, 4, offset, colorTexto);
    prenderPixel(0, 5, offset, colorTexto);
    prenderPixel(0, 6, offset, colorTexto);
    prenderPixel(1, 4, offset, colorTexto);
    prenderPixel(2, 3, offset, colorTexto);
    prenderPixel(2, 5, offset, colorTexto);
    prenderPixel(3, 2, offset, colorTexto);
    prenderPixel(3, 6, offset, colorTexto);
}

void dibujarL(int offset) {
    prenderPixel(1,0, offset, colorTexto);
    prenderPixel(2,0, offset, colorTexto);
    prenderPixel(2,1, offset, colorTexto);
    prenderPixel(2,2, offset, colorTexto);
    prenderPixel(2,3, offset, colorTexto);
    prenderPixel(2,4, offset, colorTexto);
    prenderPixel(2,5, offset, colorTexto);
    prenderPixel(2,6, offset, colorTexto);
    prenderPixel(1,6, offset, colorTexto);
    prenderPixel(3,6, offset, colorTexto);
}

void dibujarM(int offset) {
    prenderPixel(0, 2, offset, colorTexto);
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(0, 4, offset, colorTexto);
    prenderPixel(0, 5, offset, colorTexto);
    prenderPixel(0, 6, offset, colorTexto);
    prenderPixel(1, 2, offset, colorTexto);
    prenderPixel(2, 3, offset, colorTexto);
    prenderPixel(2, 4, offset, colorTexto);
    prenderPixel(2, 5, offset, colorTexto);
    prenderPixel(2, 6, offset, colorTexto);
    prenderPixel(3, 2, offset, colorTexto);
    prenderPixel(4, 3, offset, colorTexto);
    prenderPixel(4, 4, offset, colorTexto);
    prenderPixel(4, 5, offset, colorTexto);
    prenderPixel(4, 6, offset, colorTexto);
}


void dibujarN(int offset) {
    prenderPixel(0, 2, offset, colorTexto);
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(0, 4, offset, colorTexto);
    prenderPixel(0, 5, offset, colorTexto);
    prenderPixel(0, 6, offset, colorTexto);
    prenderPixel(1, 3, offset, colorTexto);
    prenderPixel(2, 2, offset, colorTexto);
    prenderPixel(3, 2, offset, colorTexto);
    prenderPixel(4, 3, offset, colorTexto);
    prenderPixel(4, 4, offset, colorTexto);
    prenderPixel(4, 5, offset, colorTexto);
    prenderPixel(4, 6, offset, colorTexto);
}

void dibujarEnie(int offset) {
    prenderPixel(0, 2, offset, colorTexto);
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(0, 4, offset, colorTexto);
    prenderPixel(0, 5, offset, colorTexto);
    prenderPixel(0, 6, offset, colorTexto);
    prenderPixel(1, 1, offset, colorTexto);
    prenderPixel(1, 3, offset, colorTexto);
    prenderPixel(2, 1, offset, colorTexto);
    prenderPixel(2, 2, offset, colorTexto);
    prenderPixel(3, 1, offset, colorTexto);
    prenderPixel(3, 2, offset, colorTexto);
    prenderPixel(4, 3, offset, colorTexto);
    prenderPixel(4, 4, offset, colorTexto);
    prenderPixel(4, 5, offset, colorTexto);
    prenderPixel(4, 6, offset, colorTexto);
}

void dibujarO(int offset) {
    prenderPixel(1,2, offset, colorTexto);
    prenderPixel(2,2, offset, colorTexto);
    prenderPixel(3,2, offset, colorTexto); 
    prenderPixel(0,3, offset, colorTexto);
    prenderPixel(4,3, offset, colorTexto);
    prenderPixel(0,4, offset, colorTexto);
    prenderPixel(4,4, offset, colorTexto);
    prenderPixel(0,5, offset, colorTexto);
    prenderPixel(4,5, offset, colorTexto);
    prenderPixel(1,6, offset, colorTexto);
    prenderPixel(2,6, offset, colorTexto);
    prenderPixel(3,6, offset, colorTexto);
}

void dibujarOConTilde(int offset) {
    dibujarO(offset);
    prenderPixel(3,0, offset, colorTexto);
    prenderPixel(2,1, offset, colorTexto);
}

void dibujarP(int offset) {
    prenderPixel(0, 2, offset, colorTexto);
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(0, 4, offset, colorTexto);
    prenderPixel(0, 5, offset, colorTexto);
    prenderPixel(0, 6, offset, colorTexto);
    prenderPixel(0, 7, offset, colorTexto);
    prenderPixel(1, 3, offset, colorTexto);
    prenderPixel(1, 4, offset, colorTexto);
    prenderPixel(2, 2, offset, colorTexto);
    prenderPixel(2, 5, offset, colorTexto);
    prenderPixel(3, 2, offset, colorTexto);
    prenderPixel(3, 5, offset, colorTexto);
    prenderPixel(4, 3, offset, colorTexto);
    prenderPixel(4, 4, offset, colorTexto);
}


void dibujarQ(int offset) {
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(0, 4, offset, colorTexto);
    prenderPixel(1, 2, offset, colorTexto);
    prenderPixel(1, 5, offset, colorTexto);
    prenderPixel(2, 2, offset, colorTexto);
    prenderPixel(2, 5, offset, colorTexto);
    prenderPixel(3, 3, offset, colorTexto);
    prenderPixel(3, 4, offset, colorTexto);
    prenderPixel(4, 2, offset, colorTexto);
    prenderPixel(4, 3, offset, colorTexto);
    prenderPixel(4, 4, offset, colorTexto);
    prenderPixel(4, 5, offset, colorTexto);
    prenderPixel(4, 6, offset, colorTexto);
    prenderPixel(4, 7, offset, colorTexto);
}

void dibujarR(int offset) {
    prenderPixel(0, 2, offset, colorTexto);
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(0, 4, offset, colorTexto);
    prenderPixel(0, 5, offset, colorTexto);
    prenderPixel(0, 6, offset, colorTexto);   
    prenderPixel(1, 3, offset, colorTexto);
    prenderPixel(2, 2, offset, colorTexto);
    prenderPixel(3, 2, offset, colorTexto);
    prenderPixel(4, 3, offset, colorTexto);
}

void dibujarS(int offset) {
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(0, 6, offset, colorTexto);
    prenderPixel(1, 2, offset, colorTexto);
    prenderPixel(1, 4, offset, colorTexto);
    prenderPixel(1, 6, offset, colorTexto);
    prenderPixel(2, 2, offset, colorTexto);
    prenderPixel(2, 4, offset, colorTexto);
    prenderPixel(2, 6, offset, colorTexto);
    prenderPixel(3, 2, offset, colorTexto);
    prenderPixel(3, 4, offset, colorTexto);
    prenderPixel(3, 6, offset, colorTexto);
    prenderPixel(4, 2, offset, colorTexto);
    prenderPixel(4, 5, offset, colorTexto);
}

void dibujarT(int offset) {
    prenderPixel(0,2, offset, colorTexto);
    prenderPixel(1,2, offset, colorTexto);
    prenderPixel(2,0, offset, colorTexto);
    prenderPixel(2,1, offset, colorTexto);
    prenderPixel(2,2, offset, colorTexto);
    prenderPixel(2,3, offset, colorTexto);
    prenderPixel(2,4, offset, colorTexto);
    prenderPixel(2,5, offset, colorTexto);
    prenderPixel(3,2, offset, colorTexto);
    prenderPixel(3,6, offset, colorTexto);
    prenderPixel(4,2, offset, colorTexto);
    prenderPixel(4,5, offset, colorTexto);
}

void dibujarU(int offset) {
    prenderPixel(0, 2, offset, colorTexto);
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(0, 4, offset, colorTexto);
    prenderPixel(0, 5, offset, colorTexto);
    prenderPixel(1, 6, offset, colorTexto);
    prenderPixel(2, 6, offset, colorTexto);
    prenderPixel(3, 5, offset, colorTexto);
    prenderPixel(4, 2, offset, colorTexto);
    prenderPixel(4, 3, offset, colorTexto);
    prenderPixel(4, 4, offset, colorTexto);
    prenderPixel(4, 5, offset, colorTexto);
    prenderPixel(4, 6, offset, colorTexto);
}

void dibujarUConTilde(int offset) {
    dibujarU(offset);
    prenderPixel(3,0, offset, colorTexto);
    prenderPixel(2,1, offset, colorTexto);
}

void dibujarUConDieresis(int offset) {
    dibujarU(offset);
    prenderPixel(1,1, offset, colorTexto);
    prenderPixel(3,1, offset, colorTexto);
}

void dibujarV(int offset) {
    prenderPixel(0, 2, offset, colorTexto);
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(0, 4, offset, colorTexto);
    prenderPixel(1, 5, offset, colorTexto);
    prenderPixel(2, 6, offset, colorTexto);
    prenderPixel(3, 5, offset, colorTexto);
    prenderPixel(4, 2, offset, colorTexto);
    prenderPixel(4, 3, offset, colorTexto);
    prenderPixel(4, 4, offset, colorTexto);   
}

void dibujarW(int offset) {
    prenderPixel(0, 2, offset, colorTexto);
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(0, 4, offset, colorTexto);
    prenderPixel(0, 5, offset, colorTexto);
    prenderPixel(1, 6, offset, colorTexto);
    prenderPixel(2, 4, offset, colorTexto);
    prenderPixel(2, 5, offset, colorTexto);
    prenderPixel(3, 6, offset, colorTexto);
    prenderPixel(4, 2, offset, colorTexto);
    prenderPixel(4, 3, offset, colorTexto);
    prenderPixel(4, 4, offset, colorTexto);  
    prenderPixel(4, 5, offset, colorTexto); 
}

void dibujarX(int offset) {
    prenderPixel(0, 2, offset, colorTexto);
    prenderPixel(0, 6, offset, colorTexto);
    prenderPixel(1, 3, offset, colorTexto);
    prenderPixel(1, 5, offset, colorTexto);
    prenderPixel(2, 4, offset, colorTexto);
    prenderPixel(3, 3, offset, colorTexto);
    prenderPixel(3, 5, offset, colorTexto);
    prenderPixel(4, 2, offset, colorTexto);
    prenderPixel(4, 6, offset, colorTexto); 
}

void dibujarY(int offset) {
    prenderPixel(0, 2, offset, colorTexto);
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(0, 6, offset, colorTexto);
    prenderPixel(1, 4, offset, colorTexto);
    prenderPixel(1, 7, offset, colorTexto);
    prenderPixel(2, 4, offset, colorTexto);
    prenderPixel(2, 7, offset, colorTexto);
    prenderPixel(3, 4, offset, colorTexto);
    prenderPixel(3, 7, offset, colorTexto);
    prenderPixel(4, 2, offset, colorTexto);
    prenderPixel(4, 3, offset, colorTexto);
    prenderPixel(4, 4, offset, colorTexto);
    prenderPixel(4, 5, offset, colorTexto);
    prenderPixel(4, 6, offset, colorTexto); 
}

void dibujarZ(int offset) {
    prenderPixel(0, 2, offset, colorTexto);
    prenderPixel(0, 6, offset, colorTexto);
    prenderPixel(1, 2, offset, colorTexto);
    prenderPixel(1, 5, offset, colorTexto);
    prenderPixel(1, 6, offset, colorTexto);
    prenderPixel(2, 2, offset, colorTexto);
    prenderPixel(2, 4, offset, colorTexto);
    prenderPixel(2, 6, offset, colorTexto);
    prenderPixel(3, 2, offset, colorTexto);
    prenderPixel(3, 3, offset, colorTexto);
    prenderPixel(3, 6, offset, colorTexto);
    prenderPixel(4, 2, offset, colorTexto);
    prenderPixel(4, 6, offset, colorTexto); 
}

void dibujarParentesisApertura(int offset) {
    prenderPixel(1, 2, offset, colorTexto);
    prenderPixel(1, 3, offset, colorTexto);
    prenderPixel(1, 4, offset, colorTexto);
    prenderPixel(2, 1, offset, colorTexto);
    prenderPixel(2, 5, offset, colorTexto);
    prenderPixel(3, 0, offset, colorTexto);
    prenderPixel(3, 6, offset, colorTexto); 
}

void dibujarParentesisCierre(int offset) {
    prenderPixel(1, 0, offset, colorTexto);
    prenderPixel(1, 6, offset, colorTexto);
    prenderPixel(2, 1, offset, colorTexto);
    prenderPixel(2, 5, offset, colorTexto);
    prenderPixel(3, 2, offset, colorTexto);
    prenderPixel(3, 3, offset, colorTexto); 
    prenderPixel(3, 4, offset, colorTexto); 
}

void dibujarComa(int offset) {
    prenderPixel(1, 7, offset, colorTexto);
    prenderPixel(2, 4, offset, colorTexto);
    prenderPixel(2, 5, offset, colorTexto);
    prenderPixel(2, 6, offset, colorTexto);
    prenderPixel(3, 4, offset, colorTexto);
    prenderPixel(3, 5, offset, colorTexto); 
}

void dibujarPuntoYComa(int offset) {
    prenderPixel(1, 6, offset, colorTexto);
    prenderPixel(2, 2, offset, colorTexto);
    prenderPixel(2, 4, offset, colorTexto);
    prenderPixel(2, 5, offset, colorTexto); 
}

void dibujarDosPuntos(int offset) {
    prenderPixel(2, 2, offset, colorTexto);
    prenderPixel(2, 4, offset, colorTexto); 
}

void dibujarPunto(int offset) {
    prenderPixel(2, 5, offset, colorTexto);
    prenderPixel(2, 6, offset, colorTexto);
    prenderPixel(3, 5, offset, colorTexto);
    prenderPixel(3, 6, offset, colorTexto); 
}

void dibujarGuionMedio(int offset) {
    prenderPixel(0, 3, offset, colorTexto);
    prenderPixel(1, 3, offset, colorTexto);
    prenderPixel(2, 3, offset, colorTexto);
    prenderPixel(3, 3, offset, colorTexto); 
    prenderPixel(4, 3, offset, colorTexto); 
}

void dibujarComilla(int offset) {
    prenderPixel(1, 0, offset, colorTexto);
    prenderPixel(1, 1, offset, colorTexto);
    prenderPixel(1, 2, offset, colorTexto);
    prenderPixel(3, 0, offset, colorTexto);
    prenderPixel(3, 1, offset, colorTexto);
    prenderPixel(3, 2, offset, colorTexto);  
}

void dibujarAdmiracionApertura(int offset) {
    prenderPixel(2, 3, offset, colorTexto);
    prenderPixel(2, 4, offset, colorTexto);
    prenderPixel(2, 5, offset, colorTexto);
    prenderPixel(2, 6, offset, colorTexto);
    prenderPixel(2, 7, offset, colorTexto);
    prenderPixel(2, 1, offset, colorTexto);  
}

void dibujarAdmiracionCierre(int offset) {
    prenderPixel(2, 0, offset, colorTexto);
    prenderPixel(2, 1, offset, colorTexto);
    prenderPixel(2, 2, offset, colorTexto);
    prenderPixel(2, 3, offset, colorTexto);
    prenderPixel(2, 4, offset, colorTexto);
    prenderPixel(2, 6, offset, colorTexto);  
}

void dibujarPreguntaApertura(int offset) {
    prenderPixel(0, 5, offset, colorTexto);
    prenderPixel(0, 6, offset, colorTexto);
    prenderPixel(1, 4, offset, colorTexto);
    prenderPixel(1, 7, offset, colorTexto);
    prenderPixel(2, 1, offset, colorTexto);
    prenderPixel(2, 3, offset, colorTexto);  
    prenderPixel(2, 4, offset, colorTexto);  
    prenderPixel(2, 7, offset, colorTexto); 
    prenderPixel(3, 7, offset, colorTexto);   
    prenderPixel(4, 6, offset, colorTexto);  
}

void dibujarPreguntaCierre(int offset) {
    prenderPixel(0, 1, offset, colorTexto);
    prenderPixel(1, 0, offset, colorTexto);
    prenderPixel(2, 0, offset, colorTexto);
    prenderPixel(2, 3, offset, colorTexto);
    prenderPixel(2, 4, offset, colorTexto);
    prenderPixel(2, 6, offset, colorTexto);  
    prenderPixel(3, 0, offset, colorTexto);  
    prenderPixel(3, 3, offset, colorTexto); 
    prenderPixel(4, 1, offset, colorTexto);   
    prenderPixel(4, 2, offset, colorTexto);  
}

void dibujarEspacio(int offset) {
  
}

void dibujarEnter(int offset) {

  dibujarEspacio(offset);
  dibujarEspacio(offset);
  dibujarEspacio(offset);
  dibujarEspacio(offset);
  dibujarEspacio(offset);
}

void prenderPixel(int x, int y, int offset, uint32_t colorTexto) {

  if(x+offset <= 59 && x+offset >= 0) {
    matrix.setPixelColor(obtenerPixel(x+offset,y), colorTexto);
  }
  
}

int obtenerPixel(int x, int y) {

  if(y % 2 > 0) {
    return (60*y+59)-x;
  }
  
  return y*60 + x;
}

void mostrarTexto(char* texto, int nuevoOffset, int longitudTexto) {

  for(int i=0; i<longitudTexto; i++) {
    char letra = texto[i];
    switch(letra) {
      case 'a':
        dibujarA(nuevoOffset+offset*i);
        break;
      case 'b':
        dibujarB(nuevoOffset+offset*i);
        break;
      case 'c':
        dibujarC(nuevoOffset+offset*i);
        break;
      case 'd':
        dibujarD(nuevoOffset+offset*i);
        break;
      case 'e':
        dibujarE(nuevoOffset+offset*i);
        break;
      case 'f':
        dibujarF(nuevoOffset+offset*i);
        break;
      case 'g':
        dibujarG(nuevoOffset+offset*i);
        break;  
      case 'h':
        dibujarH(nuevoOffset+offset*i);
        break;
      case 'i':
        dibujarI(nuevoOffset+offset*i);
        break;
      case 'j':
        dibujarJ(nuevoOffset+offset*i);
        break;
      case 'k':
        dibujarK(nuevoOffset+offset*i);
        break;
      case 'l':
        dibujarL(nuevoOffset+offset*i);
        break;
      case 'm':
        dibujarM(nuevoOffset+offset*i);
        break;
      case 'n':
        dibujarN(nuevoOffset+offset*i);
        break;
      case 'o':
        dibujarO(nuevoOffset+offset*i);
        break;
      case 'p':
        dibujarP(nuevoOffset+offset*i);
        break;
      case 'q':
        dibujarQ(nuevoOffset+offset*i);
        break;
      case 'r':
        dibujarR(nuevoOffset+offset*i);
        break;
      case 's':
        dibujarS(nuevoOffset+offset*i);
        break;
      case 't':
        dibujarT(nuevoOffset+offset*i);
        break;
      case 'u':
        dibujarU(nuevoOffset+offset*i);
        break;
      case 'v':
        dibujarV(nuevoOffset+offset*i);
        break;
      case 'w':
        dibujarW(nuevoOffset+offset*i);
        break;
      case 'x':
        dibujarX(nuevoOffset+offset*i);
        break;
      case 'y':
        dibujarY(nuevoOffset+offset*i);
        break;
      case 'z':
        dibujarZ(nuevoOffset+offset*i);
        break;
      case '¡':
        dibujarAdmiracionApertura(nuevoOffset+offset*i);
        break;
      case '!':
        dibujarAdmiracionCierre(nuevoOffset+offset*i);
        break;
      case '¿':
        dibujarPreguntaApertura(nuevoOffset+offset*i);
        break;
      case '?':
        dibujarPreguntaCierre(nuevoOffset+offset*i);
        break;
      case '.':
        dibujarPunto(nuevoOffset+offset*i);
        break;
      case ':':
        dibujarDosPuntos(nuevoOffset+offset*i);
        break;
      case ';':
        dibujarPuntoYComa(nuevoOffset+offset*i);
        break;
      case ',':
        dibujarComa(nuevoOffset+offset*i);
        break;
      case '-':
        dibujarGuionMedio(nuevoOffset+offset*i);
        break;
      case '(':
        dibujarParentesisApertura(nuevoOffset+offset*i);
        break;
      case ')':
        dibujarParentesisCierre(nuevoOffset+offset*i);
        break;
      case 'á':
        dibujarAConTilde(nuevoOffset+offset*i);
        break;
      case 'é':
        dibujarEConTilde(nuevoOffset+offset*i);
        break;
      case 'í':
        dibujarIConTilde(nuevoOffset+offset*i);
        break;
      case 'ó':
        dibujarOConTilde(nuevoOffset+offset*i);
        break;
      case 'ú':
        dibujarUConTilde(nuevoOffset+offset*i);
        break;
      case 'ü':
        dibujarUConDieresis(nuevoOffset+offset*i);
        break;
      case '\n':
        dibujarEnter(nuevoOffset+offset*i);
        break;
      case ' ':
        dibujarEspacio(nuevoOffset+offset*i);
        break;
      case '"':
        dibujarComilla(nuevoOffset+offset*i);
        break;
      default:
        dibujarGuionMedio(nuevoOffset+offset*i);
        break;
    }     
  }

  matrix.show();
  delay(30);
  matrix.clear();
  
}


void scroll(char texto[]) {

  int longitudTexto = strlen(texto);

  //Serial.println(longitudTexto);

  int nuevoOffset = 60;
  int i = 0;

  while(true) {

    mostrarTexto(texto, nuevoOffset, longitudTexto);

    int yaMostreTodasLasLetras = nuevoOffset+offset*(longitudTexto-1);
      
    if(yaMostreTodasLasLetras < 0) {
      matrix.show();
      break;
    }
    
    nuevoOffset--;
  }
 
}
