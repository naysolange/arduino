
#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"

#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer
#define LDRPin A0 
#define THRESHOLD 850

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor

#define CANTIDAD_TEXTOS 6
const char texto0[] PROGMEM = "NO DAN LAS CUENTAS"; 
const char texto1[] PROGMEM = "15.9% del PBI";
const char texto2[] PROGMEM = "75.7%";
const char texto3[] PROGMEM = "96 millones de horas";
const char texto4[] PROGMEM = "trabajo trabajo trabajo";
const char texto5[] PROGMEM = "NO remunerado";
char buffer[100];  // make sure this is large enough for the largest string it must hold

// Then set up a table to refer to your strings.
const char *const textos[] PROGMEM = {texto0, texto1, texto2, texto3, texto4, texto5};

void setup() {
  mySerial.begin(19200);  // Initialize SoftwareSerial
  Serial.begin(9600);
  printer.begin();        // Init printer (same regardless of serial type)
  pinMode(LDRPin, INPUT);
}

void loop() {

  int input = analogRead(LDRPin);
  Serial.println(input);

  if(input < THRESHOLD) {
      printer.setSize('L'); 
      printer.justify('C');
      printer.setLineHeight(40);

      int posicionRandom = random(0, CANTIDAD_TEXTOS);
      strcpy_P(buffer, (char *)pgm_read_word(&(textos[posicionRandom])));  
      Serial.println(buffer);

      printer.println(buffer);
      delay(30000);
   }

}
