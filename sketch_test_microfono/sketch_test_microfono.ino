#include <Adafruit_NeoPixel.h>

#define MIC 2
#define LED 3
#define PIN_TIRA_LED 6 
#define CANT_PIXELS 300 
#define DELAYVAL 200 

Adafruit_NeoPixel pixels(CANT_PIXELS, PIN_TIRA_LED, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(MIC, INPUT);
  pinMode(LED, OUTPUT);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {

  pixels.clear(); // Set all pixel colors to 'off'

 // Sensado de soplido
 int valorMicLeido = digitalRead(MIC);
   
 if(valorMicLeido == HIGH) {

    // Prende y apaga led que indica inicio
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    
    // Prende tira led
    for(int i=0; i<CANT_PIXELS; i++) { 
      pixels.setPixelColor(i, pixels.Color(100, 0, 170));
      pixels.show();   // Send the updated pixel colors to the hardware.
    }
    delay(DELAYVAL); 

    // Apaga tira led
    for(int i=0; i<CANT_PIXELS; i++) { 
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();   
    }
    
  }

}
