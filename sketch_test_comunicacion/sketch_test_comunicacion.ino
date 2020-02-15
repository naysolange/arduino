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
      case 'h':
        dibujarH(nuevoOffset+offset*i);
        break;
      case 'o':
       dibujarO(nuevoOffset+offset*i);
       break;
      case 'l':
       dibujarL(nuevoOffset+offset*i);
       break;
    }
  }

  matrix.show();
  delay(30);
  matrix.clear();
  
}

void scroll(char texto[]) {

  int longitudTexto = strlen(texto);

  Serial.println(longitudTexto);

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
