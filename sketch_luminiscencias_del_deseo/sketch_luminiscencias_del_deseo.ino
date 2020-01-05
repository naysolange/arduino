#include <Adafruit_NeoPixel.h>

#define MIC 2
#define LED 3
#define PIN_TIRA_LED 6 
#define CANT_PIXELS 300 
#define DELAY 3000 

Adafruit_NeoPixel pixels(CANT_PIXELS, PIN_TIRA_LED, NEO_GRB + NEO_KHZ800);
uint32_t colorTexto = pixels.Color(0, 90, 20);

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MIC, INPUT);
  pinMode(LED, OUTPUT);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  randomSeed(20);
}

String PEDIR_TEXTO = "texto";

void loop() {

 // Limpia la pantalla
 pixels.clear(); 

 mostrarPatronLuminico();
 
 // Sensado de soplido
 int valorMicLeido = digitalRead(MIC);
   
 if(valorMicLeido == HIGH) {
    Serial.println(PEDIR_TEXTO);
    // Prende y apaga led que indica petición de poesía a la raspi
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
  }

  if(Serial.available() > 0) {
    String poesia = Serial.readString();
    if(poesia.length() == 20) {
        pixels.clear();
        escribirPoema();
    }
  }


  
}


void mostrarPatronLuminico() {

 uint32_t colorLed;
 int cantidadDeVueltas = random(15,30);

 for(int i=0; i<cantidadDeVueltas; i++) {
  int ledAPrender = random(0,300);  
  switch(random(1,3)) {
    case 1:
      // Magenta
      colorLed = pixels.Color(random(50,200), 0, random(10,100));
      break;
    case 2:
     // Naranja
      colorLed = pixels.Color(random(200,255), random(50,100), 0);
      break;
  }

  colorTexto = colorLed;
 
  pixels.setPixelColor(ledAPrender, colorLed);
  pixels.show();    
 }

 delay(200);
  
}

void escribirPoema() {
  escribirFrase1Poema2();
  escribirFrase2Poema2();
  escribirFrase3Poema2();
}

void escribirFrase1Poema2() {

  dibujarG(12);
  dibujarR(20);
  dibujarI(27);
  dibujarT(33);
  dibujarA(40);
  
  pixels.show();   
  delay(DELAY);

  apagarLeds();
  
}


void escribirFrase2Poema2() {

  dibujarE(12);
  dibujarL(19);
  dibujarM(30);
  dibujarA(37);
  dibujarR(46);
  
  pixels.show();   
  delay(DELAY);

  apagarLeds();
  
}


void escribirFrase3Poema2() {

  dibujarE(6);
  dibujarS(13);
  dibujarC(20);
  dibujarU(27);
  dibujarC(34);
  dibujarH(41);
  dibujarE(48);
  
  pixels.show();   
  delay(DELAY);

  apagarLeds();
  
}

void dibujarM(uint16_t offset) {
  pixels.setPixelColor(obtenerPixel(0,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,4+offset), colorTexto);
}

void dibujarL(uint16_t offset) {
  pixels.setPixelColor(obtenerPixel(0,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,4+offset), colorTexto);
}

void dibujarA(uint16_t offset) {
  pixels.setPixelColor(obtenerPixel(0,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,4+offset), colorTexto); 
}

void dibujarT(uint16_t offset) {
  pixels.setPixelColor(obtenerPixel(0,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,2+offset), colorTexto);
}

void dibujarI(uint16_t offset) {
  pixels.setPixelColor(obtenerPixel(0,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,2+offset), colorTexto);
}

void dibujarE(uint16_t offset) {
  pixels.setPixelColor(obtenerPixel(0,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,4+offset), colorTexto);
}

void dibujarR(uint16_t offset) {
  pixels.setPixelColor(obtenerPixel(0,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,4+offset), colorTexto);
}

void dibujarS(uint16_t offset) {
  pixels.setPixelColor(obtenerPixel(0,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,4+offset), colorTexto);
}

void dibujarU(uint16_t offset) {
  pixels.setPixelColor(obtenerPixel(0,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,4+offset), colorTexto);
}


void dibujarC(uint16_t offset) {
  pixels.setPixelColor(obtenerPixel(0,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,4+offset), colorTexto);
}

void dibujarG(uint16_t offset) {
  pixels.setPixelColor(obtenerPixel(0,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,4+offset), colorTexto);
}

void dibujarH(uint16_t offset) {
  pixels.setPixelColor(obtenerPixel(0,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(0,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(1,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,1+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,2+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,3+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(2,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(3,4+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,0+offset), colorTexto);
  pixels.setPixelColor(obtenerPixel(4,4+offset), colorTexto);
}

void apagarLeds() {
   for(int i=0; i<CANT_PIXELS; i++) { 
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();   
    }
}

uint16_t obtenerPixel(uint16_t x, uint16_t y) {
  return x*60 + y;
}
