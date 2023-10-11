// Este programa reacciona a un soplido y enciende/apaga una tira led de neopixel con efecto latido
// Licensed with CC BY-NC-SA 4.0 https://creativecommons.org/licenses/by-nc-sa/4.0/
// by naysolange.xyz

#include <Adafruit_NeoPixel.h>

#define PIN_TIRA_LED 6 
#define CANT_PIXELS 16
#define MIC 2

Adafruit_NeoPixel matrix(CANT_PIXELS, PIN_TIRA_LED, NEO_GRB + NEO_KHZ800);

int intensidad = 0;
int velocidadLatido = 2;
int valorMicLeido = LOW;
bool ledsON = false;
unsigned long tiempoUltimaMedicion = 0;
const unsigned long intervaloMedicion = 1000;

void setup() {
   Serial.begin(9600);
   pinMode(MIC, INPUT);
   matrix.begin();
   apagarLeds();
}

void loop() {

  unsigned long tiempoActual = millis();

  if (tiempoUltimaMedicion == 0 || tiempoActual - tiempoUltimaMedicion >= intervaloMedicion) {
     valorMicLeido = digitalRead(MIC);
  }

  if(valorMicLeido == HIGH) {
    if(!ledsON) {
      ledsON = true;
      Serial.println("LEDS ON");  
    } else {
      ledsON = false;
      apagarLeds();
      Serial.println("LEDS OFF");
    }

    tiempoUltimaMedicion = tiempoActual;
    valorMicLeido = LOW;
  } 
   
  if(ledsON){
    prenderLeds();
  }

}

void prenderLeds() {
  // Aumenta gradualmente la intensidad
  for(int i = 0; i < 255; i += velocidadLatido) {
    intensidad = i;
    setColor(intensidad);
  }

  // Disminuye gradualmente la intensidad
  for(int i = 255; i >= 0; i -= velocidadLatido) {
    intensidad = i;
    setColor(intensidad);
  }
}

void apagarLeds() {
  matrix.clear();
  matrix.show();
}

void setColor(int intensidad) {
  for(int i = 0; i < CANT_PIXELS; i++) {
    matrix.setPixelColor(i, matrix.Color(20 * intensidad / 255, 0, 20 * intensidad / 255));
  }
  matrix.show();
}
