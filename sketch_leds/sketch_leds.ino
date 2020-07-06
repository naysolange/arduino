
const int red1 = 6;
const int green1 = 5;
const int blue1 = 3;
const int red2 = 9;
const int green2 = 10;
const int blue2 = 11;

void setup() {
 pinMode(red1, OUTPUT);
 pinMode(green1, OUTPUT);
 pinMode(blue1, OUTPUT);
 pinMode(red2, OUTPUT);
 pinMode(green2, OUTPUT);
 pinMode(blue2, OUTPUT);
}

void loop() {

  // amarillo
  /*analogWrite(red1,255);
  analogWrite(green1,150);
  analogWrite(blue1,0);*/
 /* analogWrite(red2,255);
  analogWrite(green2,150);
  analogWrite(blue2,0);*/

  // azul
  /*analogWrite(red2,10);
  analogWrite(green2,10);
  analogWrite(blue2,150);*/

  // verde oscuro
  analogWrite(red2,0);
  analogWrite(green2,10);
  analogWrite(blue2,3);

  // Lila 
  analogWrite(red1,7);
  analogWrite(green1,5);
  analogWrite(blue1,10);
   
}
