#include <Adafruit_NeoPixel.h>

#define CANT_PIXELS 16
#define PIN_TIRA_LED 6

class Strip
{
  
public:
  uint8_t   effect;
  uint8_t   effects;
  uint16_t  effStep;
  unsigned long effStart;
  Adafruit_NeoPixel strip;
  
  Strip(uint16_t leds, uint8_t pin, uint8_t toteffects, uint16_t striptype) : strip(leds, pin, striptype) {
    effect = -1;
    effects = toteffects;
    Reset();
  }
  
  void Reset(){
    effStep = 0;
    effect = (effect + 1) % effects;
    effStart = millis();
  }
  
};

struct Loop
{
  uint8_t currentChild;
  uint8_t childs;
  bool timeBased;
  uint16_t cycles;
  uint16_t currentTime;
  Loop(uint8_t totchilds, bool timebased, uint16_t tottime) {currentTime=0;currentChild=0;childs=totchilds;timeBased=timebased;cycles=tottime;}
};

// Variables globales
Strip tiraLed(CANT_PIXELS, PIN_TIRA_LED, CANT_PIXELS, NEO_GRB + NEO_KHZ800);
struct Loop strip0loop0(1, false, 1);



void setup() {

  tiraLed.strip.begin();
}

void loop() {

  // Esta sería la función que hay que llamar cuando se activan los motores para el abrazo
  lucesAbrazo();

  // Esta sería la función que hay que llamar cuando se activan los motores para el toque. No pueden activarse ambas en el mismo loop, por eso esta comentada, probar de a una.
  //lucesToque();
}

void lucesAbrazo() {
  if(strip0_loop0() & 0x01)
    tiraLed.strip.show();
}

void lucesToque() {

  tiraLed.strip.clear();

  // Acá ver que color le vamos a poner al toque, por ahora puse verde
  uint32_t colorToque = tiraLed.strip.Color(0, 150, 0);
  
  prenderLuces(colorToque);
  delay(50);

  apagarLuces();
  delay(50);

  prenderLuces(colorToque);
  delay(50);

  apagarLuces();
  delay(50);
  
}

void apagarLuces() {

  for(int i=0; i<CANT_PIXELS; i++) {
    tiraLed.strip.setPixelColor(i, (0,0,0));
  }

  tiraLed.strip.show();

}

void prenderLuces(uint32_t colorToque) {
  
  for(int i=0; i<CANT_PIXELS; i++) {
    tiraLed.strip.setPixelColor(i, colorToque);
  }
  
  tiraLed.strip.show();
}


uint8_t strip0_loop0() {
  uint8_t ret = 0x00;
  switch(strip0loop0.currentChild) {
    case 0: 
           ret = strip0_loop0_eff0();break;
  }
  if(ret & 0x02) {
    ret &= 0xfd;
    if(strip0loop0.currentChild + 1 >= strip0loop0.childs) {
      strip0loop0.currentChild = 0;
      if(++strip0loop0.currentTime >= strip0loop0.cycles) {strip0loop0.currentTime = 0; ret |= 0x02;}
    }
    else {
      strip0loop0.currentChild++;
    }
  };
  return ret;
}

uint8_t strip0_loop0_eff0() {
  // Strip ID: 0 - Effect: Rainbow - LEDS: 16
  // Steps: 16 - Delay: 20
  // Colors: 3 (255.0.0, 255.147.0, 255.75.147) se pueden tocar estos valores en el switch para probar con otros colores
  // Options: rainbowlen=16, toLeft=true, 
  int rainbowlen = CANT_PIXELS;
  if(millis() - tiraLed.effStart < 20 * (tiraLed.effStep)) return 0x00;
  float factor1, factor2;
  uint16_t ind;
  for(uint16_t j=0;j<rainbowlen;j++) {
    ind = tiraLed.effStep + j * 1;
    switch((int)((ind % rainbowlen) / 20)) {
      case 0: factor1 = 1.0 - ((float)(ind % rainbowlen - 0 * 20) / 20);
              factor2 = (float)((int)(ind - 0) % rainbowlen) / 20;
              tiraLed.strip.setPixelColor(j, 255 * factor1 + 255 * factor2, 0 * factor1 + 147 * factor2, 0 * factor1 + 0 * factor2);
              break;
      case 1: factor1 = 1.0 - ((float)(ind % rainbowlen - 1 * 20) / 20);
              factor2 = (float)((int)(ind - 20) % rainbowlen) / 20;
              tiraLed.strip.setPixelColor(j, 255 * factor1 + 255 * factor2, 147 * factor1 + 75 * factor2, 0 * factor1 + 147 * factor2);
              break;
      case 2: factor1 = 1.0 - ((float)(ind % rainbowlen - 2 * 20) / 20);
              factor2 = (float)((int)(ind - 40) % rainbowlen) / 20;
              tiraLed.strip.setPixelColor(j, 255 * factor1 + 255 * factor2, 75 * factor1 + 0 * factor2, 147 * factor1 + 0 * factor2);
              break;
    }
  }
  if(tiraLed.effStep >= rainbowlen) {tiraLed.Reset(); return 0x03; }
  else tiraLed.effStep++;
  return 0x01;
}
