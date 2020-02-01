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

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(50);
  matrix.setTextColor(matrix.Color(255,0,200));
}

void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  scroll("Luminiscencias del deseo", 40);
}

void scroll(char* message, int delays) {
  int maxDisplacement = strlen(message) * pixelPerChar + matrix.width();
  if(++line_pass > matrix.width()) line_pass = 0;
  matrix.print(String(message));
  if(--x < -maxDisplacement) {
    x = matrix.width();
  }
  matrix.show();
  delay(delays);
}
