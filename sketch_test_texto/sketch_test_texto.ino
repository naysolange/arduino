#include <Adafruit_NeoPixel.h>

#define PIN_TIRA_LED 6 
#define NUMPIXELS 480
#define DELAYVAL 200

Adafruit_NeoPixel pixels(NUMPIXELS, PIN_TIRA_LED, NEO_GRB + NEO_KHZ800);


void setup() {
  pixels.begin();
}

void loop() {

 pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();
    delay(DELAYVAL);
  }
  
}
