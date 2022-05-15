#include "LedControl.h"

#define PIN_TOUCH A0

LedControl lc = LedControl(9,11,8,5);
int estadoTouch = 0;

void setup() {
  //Serial.begin(9600);
  
  lc.shutdown(0,false);
  lc.setIntensity(0,4);
  lc.clearDisplay(0);

  lc.shutdown(1,false);
  lc.setIntensity(1,4);
  lc.clearDisplay(1);

  lc.shutdown(2,false);
  lc.setIntensity(2,4);
  lc.clearDisplay(2);

  lc.shutdown(3,false);
  lc.setIntensity(3,4);
  lc.clearDisplay(3);

  lc.shutdown(4,false);
  lc.setIntensity(4,4);
  lc.clearDisplay(4);

}

void loop() { 


 estadoTouch = digitalRead(PIN_TOUCH);
 //Serial.println(estadoTouch);
 
 if(estadoTouch == 1) {
   for(int modulo = 0; modulo < 5; modulo++) {
      for(int fila = 0; fila < 8; fila++) {
        for(int columna = 0; columna < 8; columna++) {
          lc.setLed(modulo,fila,columna,true);
          delay(50);
          //lc.setLed(modulo,fila,columna,false);
          //delay(50);
        }
      }
    }
 }

  lc.clearDisplay(0);
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);
  lc.clearDisplay(4);

}
