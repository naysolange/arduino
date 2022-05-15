/*
  PROGMEM string demo
  How to store a table of strings in program memory (flash),
  and retrieve them.

  Information summarized from:
  http://www.nongnu.org/avr-libc/user-manual/pgmspace.html

  Setting up a table (array) of strings in program memory is slightly complicated, but
  here is a good template to follow.

  Setting up the strings is a two-step process. First, define the strings.
*/

#define SIZE_BARRA1 6
const char barra1_verso0[] PROGMEM = "Me gusta mirarte ser"; 
const char barra1_verso1[] PROGMEM = "Es posible enamorarse de dos";
const char barra1_verso2[] PROGMEM = "No puedo aguantar mas";
const char barra1_verso3[] PROGMEM = "Quisiera ser un gatito chiquito mimado de departamento";
const char barra1_verso4[] PROGMEM = "Dejar de escapar de mí";
const char barra1_verso5[] PROGMEM = "Somos lo que somos";


// Then set up a table to refer to your strings.
const char *const barra1[] PROGMEM = {barra1_verso0, barra1_verso1, barra1_verso2, barra1_verso3, barra1_verso4, barra1_verso5};

char buffer[65];  // make sure this is large enough for the largest string it must hold

void mostrarVersoRandom(const char *const barra[]) {

 //int posicionRandom = random(0,longitudDelArreglo);
 //Serial.println(posicionRandom);
 //Serial.println(arreglo[posicionRandom]);
 //delay(1000);

}

void setup() {
  Serial.begin(9600);
  while (!Serial);  // wait for serial port to connect. Needed for native USB
  Serial.println("OK");
}


void loop() {
  /* Using the string table in program memory requires the use of special functions to retrieve the data.
     The strcpy_P function copies a string from program space to a string in RAM ("buffer").
     Make sure your receiving string in RAM is large enough to hold whatever
     you are retrieving from program space. */

    int posicionRandom = random(0, SIZE_BARRA1);
    strcpy_P(buffer, (char *)pgm_read_word(&(barra1[posicionRandom])));  // Necessary casts and dereferencing, just copy.
    Serial.println(buffer);
    delay(500);

}
