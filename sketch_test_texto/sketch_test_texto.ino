#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>

#define PIN_TIRA_LED 6 

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(60, 8, PIN_TIRA_LED,
  NEO_MATRIX_TOP  + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB         + NEO_KHZ800);


int pixelPerChar = 4;
int y = matrix.height();
int x = matrix.width();
int pass = 0;
int line_pass = 0;
int offset = 6;

uint32_t colorTexto = matrix.Color(0, 90, 20);
boolean dibujarPatronRandom = true;

void setup() {
  Serial.begin(9600);
  matrix.begin();
}

void loop() {

  /*if(dibujarPatronRandom) {
    prenderPixel(0,0,0,colorTexto);
    matrix.show();
    dibujarPatronRandom = false;
  } else {
   
    int indice = 100;
    char poesia[indice];

    for(int i=0; i<100; i++) {
      poesia[i] = 'a';
    }
    
    scroll(poesia);
  }*/
  /*matrix.setTextWrap(false);
  matrix.setBrightness(50);
  matrix.clear();
  matrix.setCursor(0,0);
  matrix.print("z");*/
  dibujarZ(0);
  matrix.show();
  
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
      dibujarPatronRandom = true;
      break;
    }
    
    nuevoOffset--;
  }
 
}
