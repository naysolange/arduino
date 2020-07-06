#define PIN_LED_ROJO 9
#define PIN_LED_AMARILLO 10
#define PIN_LED_VERDE 11

#define MEDIO_SEGUNDO 500

void setup() {
  pinMode(PIN_LED_ROJO, OUTPUT);
  pinMode(PIN_LED_AMARILLO, OUTPUT);
  pinMode(PIN_LED_VERDE, OUTPUT);
}

void loop() {

  // Semáforo
  
  // Rojo
  digitalWrite(PIN_LED_ROJO, HIGH);
  digitalWrite(PIN_LED_AMARILLO, LOW);
  digitalWrite(PIN_LED_VERDE, LOW);
  delay(MEDIO_SEGUNDO);
  
  // Rojo --> Verde
  digitalWrite(PIN_LED_ROJO, HIGH);
  digitalWrite(PIN_LED_AMARILLO, HIGH);
  delay(MEDIO_SEGUNDO);
  digitalWrite(PIN_LED_ROJO, LOW);
  digitalWrite(PIN_LED_AMARILLO, LOW);
  digitalWrite(PIN_LED_VERDE, HIGH);
  delay(MEDIO_SEGUNDO);

  // Verde --> Rojo
  digitalWrite(PIN_LED_VERDE, LOW);
  digitalWrite(PIN_LED_AMARILLO, HIGH);
  delay(MEDIO_SEGUNDO);
  digitalWrite(PIN_LED_AMARILLO, LOW);
  digitalWrite(PIN_LED_ROJO, HIGH);

}
