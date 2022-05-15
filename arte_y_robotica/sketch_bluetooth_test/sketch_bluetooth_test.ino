//OJO SERIAL PONER EN AMBOS NL & CR 
//State a positivo o pin9

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RX | TX // Ojo. invertir en el BlueTo

void setup()
{
  //pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  Serial.begin(38400);
  delay(1000);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);
  //BTSerial.begin(115200);
}

void loop()
{
   BTSerial.write("AT");

  if (BTSerial.available())
    Serial.write(BTSerial.read());

   
}
