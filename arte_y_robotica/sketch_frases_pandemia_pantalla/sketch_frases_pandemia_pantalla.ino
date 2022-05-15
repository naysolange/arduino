#include <Adafruit_NeoPixel.h>

#define PIN_TIRA_LED 6 
#define CANT_PIXELS 480

Adafruit_NeoPixel matrix(CANT_PIXELS, PIN_TIRA_LED, NEO_GRB + NEO_KHZ800);

int offset = 6;
uint32_t colorTexto = matrix.Color(0, 90, 20);
int indice = 0;
int encabezado = 255;
int pedido = 253;
int cierre = 254;
int valor;


void setup() {
  Serial.begin(9600);
  matrix.begin();
  randomSeed(millis());
}


void loop() {

  matrix.clear();
  leerPuertoSerial();
   
}

void leerPuertoSerial(){

    while(Serial.available()>0) {
      int leido = Serial.read();

      switch (indice) {
        case 0: //indice == 0 miro que el byte sea = al encabezado
          if (leido == encabezado) {
            indice++;
          }
          break;
        case 1://indice == 1 miro si es el codigo de pedido
          valor = leido;
          indice ++;
          break;
        case 2://indice == 2 miro que el byte sea el final del mensaje
          if (leido == cierre) {
            Serial.write(leido);
            mostrarFrase();
          }
          indice = 0; //espero un nuevo mensaje
          valor = 0;
          break;
      }
    }
}

void apagarMatrix() {

  for(int i=0; i< CANT_PIXELS; i++) {
    matrix.setPixelColor(i, matrix.Color(0, 0, 0));
  }
  matrix.show(); 
}

void prenderMatrix() {

  for(int i=0; i< CANT_PIXELS; i++) {
    matrix.setPixelColor(i, matrix.Color(100, 0, 100));
  }
  matrix.show(); 
}

void mostrarFrase() {

  char frase1[] = "francisco";
  char frase2[] = "mama";
  char frase3[] = "papa";
  char frase4[] = "nino";
  char frase5[] = "abu Mary";
  char frase6[] = "abu Jose";
  char frase7[] = "somos lo que somos";

  int fraseElegida = random(7) + 1; // un valor al azar de 0 a 6 + 1
  Serial.write(fraseElegida);

  if(fraseElegida == 1) {
    // Agrega caracteres de fin de string y retorno de carro
      int tamanio1 = sizeof(frase1);
      Serial.write(tamanio1);
      
      char fraseParaPantalla1[tamanio1+2];
    
      for(int j=0; j<tamanio1; j++) {
        fraseParaPantalla1[j] = frase1[j];
      }
     
      fraseParaPantalla1[tamanio1] = '\0';
      fraseParaPantalla1[tamanio1+1] = '\r';
      fraseParaPantalla1[tamanio1+2] = '\n';
      scroll(fraseParaPantalla1, sizeof(fraseParaPantalla1)-2);  
    
    
  } else if(fraseElegida == 2) {

    // Agrega caracteres de fin de string y retorno de carro
      int tamanio2 = sizeof(frase2);
      Serial.write(tamanio2);
      
      char fraseParaPantalla2[tamanio2+2];
    
      for(int j=0; j<tamanio2; j++) {
        fraseParaPantalla2[j] = frase2[j];
      }
     
      fraseParaPantalla2[tamanio2] = '\0';
      fraseParaPantalla2[tamanio2+1] = '\r';
      fraseParaPantalla2[tamanio2+2] = '\n';
      scroll(fraseParaPantalla2, sizeof(fraseParaPantalla2)-2);  
      
    
  } else if(fraseElegida == 3) {
     // Agrega caracteres de fin de string y retorno de carro
      int tamanio3 = sizeof(frase3);
      Serial.write(tamanio3);
      
      char fraseParaPantalla3[tamanio3+2];
    
      for(int j=0; j<tamanio3; j++) {
        fraseParaPantalla3[j] = frase3[j];
      }
     
      fraseParaPantalla3[tamanio3] = '\0';
      fraseParaPantalla3[tamanio3+1] = '\r';
      fraseParaPantalla3[tamanio3+2] = '\n';
      scroll(fraseParaPantalla3, sizeof(fraseParaPantalla3)-2);  
      
  } else if(fraseElegida == 4) {
    // Agrega caracteres de fin de string y retorno de carro
      int tamanio4 = sizeof(frase4);
      Serial.write(tamanio4);
      
      char fraseParaPantalla4[tamanio4+2];
    
      for(int j=0; j<tamanio4; j++) {
        fraseParaPantalla4[j] = frase4[j];
      }
     
      fraseParaPantalla4[tamanio4] = '\0';
      fraseParaPantalla4[tamanio4+1] = '\r';
      fraseParaPantalla4[tamanio4+2] = '\n';
      scroll(fraseParaPantalla4, sizeof(fraseParaPantalla4)-2);  
    
  } else if(fraseElegida == 5) {
    // Agrega caracteres de fin de string y retorno de carro
      int tamanio5 = sizeof(frase5);
      Serial.write(tamanio5);
      
      char fraseParaPantalla5[tamanio5+2];
    
      for(int j=0; j<tamanio5; j++) {
        fraseParaPantalla5[j] = frase5[j];
      }
     
      fraseParaPantalla5[tamanio5] = '\0';
      fraseParaPantalla5[tamanio5+1] = '\r';
      fraseParaPantalla5[tamanio5+2] = '\n';
      scroll(fraseParaPantalla5, sizeof(fraseParaPantalla5)-2);  
      
  } else if(fraseElegida == 6) {
      // Agrega caracteres de fin de string y retorno de carro
      int tamanio6 = sizeof(frase6);
      Serial.write(tamanio6);
      
      char fraseParaPantalla6[tamanio6+2];
    
      for(int j=0; j<tamanio6; j++) {
        fraseParaPantalla6[j] = frase6[j];
      }
     
      fraseParaPantalla6[tamanio6] = '\0';
      fraseParaPantalla6[tamanio6+1] = '\r';
      fraseParaPantalla6[tamanio6+2] = '\n';
      scroll(fraseParaPantalla6, sizeof(fraseParaPantalla6)-2);  
      
  } else {
    // Agrega caracteres de fin de string y retorno de carro
      int tamanio7 = sizeof(frase7);
      Serial.write(tamanio7);
      
      char fraseParaPantalla7[tamanio7+2];
    
      for(int j=0; j<tamanio7; j++) {
        fraseParaPantalla7[j] = frase7[j];
      }
     
      fraseParaPantalla7[tamanio7] = '\0';
      fraseParaPantalla7[tamanio7+1] = '\r';
      fraseParaPantalla7[tamanio7+2] = '\n';
      scroll(fraseParaPantalla7, sizeof(fraseParaPantalla7)-2);  
    
  } 
 
  
}




uint32_t obtenerColorRandom() {
  uint32_t colorLed;
  int valorMapeado = map(valor, 0, 253, 0, 255);
  Serial.write(valorMapeado);
  colorLed = matrix.Color(valorMapeado, 0, 180);
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

void mostrarTexto(char texto[], int nuevoOffset, int longitudTexto) {

  for(int i=0; i<longitudTexto-1; i++) {
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
      case -15:
        dibujarEnie(nuevoOffset+offset*i);
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

void scroll(char texto[], int longitudTexto) {

  int nuevoOffset = 60;
  int i = 0;
  colorTexto = obtenerColorRandom();

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
