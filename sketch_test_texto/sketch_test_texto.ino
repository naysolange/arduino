#include <Adafruit_NeoPixel.h>

#define PIN_TIRA_LED 6 
#define CANT_PIXELS 480

Adafruit_NeoPixel matrix(CANT_PIXELS, PIN_TIRA_LED, NEO_GRB + NEO_KHZ800);

int offset = 6;

uint32_t colorTexto = matrix.Color(0, 90, 20);
boolean mostrarPoesia = true, mostrarPatron = true;

void setup() {
  Serial.begin(9600);
  matrix.begin();
}

void loop() {

   matrix.clear();

   mostrarPatronLuminico();
    
   if(mostrarPoesia) {
     int indice = 10;
     char poesia[indice];
  
     for(int i=0; i<10; i++) {
       poesia[i] = 'h';
     }
      
     scroll(poesia);
    }
   
  
}

void mostrarPatronLuminico() {

 uint32_t colorLed;
 int cantidadDeVueltas = random(15,50);

 for(int i=0; i<cantidadDeVueltas; i++) {
  int ledAPrender = random(0,CANT_PIXELS);  
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

  colorTexto = colorLed;
 
  matrix.setPixelColor(ledAPrender, colorLed);
  matrix.show();    
 }

 delay(200);
  
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

    //Serial.println(yaMostreTodasLasLetras);
      
    if(yaMostreTodasLasLetras < 0) {
      matrix.show();
      mostrarPoesia = false;
      break;
    }
    
    nuevoOffset--;
  }
 
}
