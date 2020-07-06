#define PIN_LED1 9
#define PIN_LED2 10
#define PIN_LED3 11
#define MEDIO_SEGUNDO 500
#define UN_SEGUNDO 1000
#define DOS_SEGUNDOS 2000

void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
}

void loop() {

  // Primera mitad del primer periodo de MEDIO_SEGUNDO
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, LOW);
  digitalWrite(PIN_LED3, LOW);
  delay(MEDIO_SEGUNDO/2);
  // Segunda mitad del primer periodo de MEDIO_SEGUNDO
  digitalWrite(PIN_LED1, HIGH);
  delay(MEDIO_SEGUNDO/2);
  
  // Primera mitad del segundo periodo de MEDIO_SEGUNDO
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, HIGH);
  delay(MEDIO_SEGUNDO/2);
  // Segunda mitad del segundo periodo de MEDIO_SEGUNDO
  digitalWrite(PIN_LED1, HIGH);
  digitalWrite(PIN_LED2, HIGH);
  delay(MEDIO_SEGUNDO/2);

  // Primera mitad del tercer periodo de MEDIO_SEGUNDO
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, LOW);
  digitalWrite(PIN_LED3, HIGH);
  delay(MEDIO_SEGUNDO/2);
  // Segunda mitad del tercer periodo de MEDIO_SEGUNDO
  digitalWrite(PIN_LED1, HIGH);
  digitalWrite(PIN_LED2, LOW);
  digitalWrite(PIN_LED3, HIGH);
  delay(MEDIO_SEGUNDO/2);

   // Primera mitad del cuarto periodo de MEDIO_SEGUNDO
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, HIGH);
  digitalWrite(PIN_LED3, HIGH);
  delay(MEDIO_SEGUNDO/2);
  // Segunda mitad del cuarto periodo de MEDIO_SEGUNDO
  digitalWrite(PIN_LED1, HIGH);
  digitalWrite(PIN_LED2, HIGH);
  digitalWrite(PIN_LED3, HIGH);
  delay(MEDIO_SEGUNDO/2);
  
  
}
