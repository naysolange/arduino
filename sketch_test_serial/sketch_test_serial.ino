void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

String PEDIR_TEXTO = "texto";
int i = 0;

void loop() {

  if(i == 0) { 
    Serial.println(PEDIR_TEXTO);
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);
    i=1;
  }

  delay(2000);

  if(Serial.available() > 0) {
    String poesia = Serial.readString();
    if(poesia.length() == 1170) {
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);
    }
  }


  
}
