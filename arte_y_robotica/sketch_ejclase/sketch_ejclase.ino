int pinBoton = A0;
int pinLed = 9;

void setup() {
  pinMode(pinBoton, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);
}



void loop() {

  boolean aux = digitalRead(pinBoton);

  digitalWrite(pinLed, !aux);
  delay(200);
  digitalWrite(pinLed, LOW);
  delay(200);  
}
