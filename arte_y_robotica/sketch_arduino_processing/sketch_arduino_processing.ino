#define MEDIA_VELOCIDAD_SONIDO 0.017175 // Mitad de la velocidad del sonido a 20°C expresada en cm/µs
#define PIN_TRIGGER 7
#define PIN_ECHO 8
#define ESPERA_ENTRE_LECTURAS 1000 // tiempo entre lecturas consecutivas en milisegundos
#define TIMEOUT_PULSO 25000 // la espera máxima de es 30 ms o 30000 µs
#define HEADER_POTE 253
#define HEADER_SENSOR_DISTANCIA 254

long distancia;
unsigned long tiempo;
unsigned long cronometro;
unsigned long reloj=0;
long valorPote;
 
void setup() {
  Serial.begin(9600); 
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_TRIGGER, OUTPUT);
  digitalWrite(PIN_TRIGGER,LOW); // Para «limpiar» el pulso del pin trigger del módulo
  delayMicroseconds(2);
}
 
void loop() {
  
  // leemos del potenciometro
  valorPote = analogRead(A0);
   // Acá como solo puedo mandar 1 byte que es un valor hasta 255, mapeo los valores del pote
  // que van desde 0 a 1023 para que vayan de 0 a 252
  valorPote = map(valorPote, 0, 1023, 0, 252);
  // Acá le mando a processing un valor que indica que el próximo valor enviado será del potenciometro
  // Utilizo arbitrariamente el 253 (por eso en el map de arriba le mando como valor máximo 252)
  Serial.write(HEADER_POTE);
  Serial.write(valorPote);
  delay(100);

  // leemos del sensor de distancia
  cronometro = millis()-reloj;
  if(cronometro > ESPERA_ENTRE_LECTURAS)
  {
    digitalWrite(PIN_TRIGGER, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(PIN_TRIGGER, LOW); 
    tiempo = pulseIn(PIN_ECHO, HIGH, TIMEOUT_PULSO); // mide el tiempo que tarda en llegar un pulso
    distancia = MEDIA_VELOCIDAD_SONIDO * tiempo;
    // Acá como solo puedo mandar 1 byte que es un valor hasta 255, mapeo los valores del sensor de distancia
    // que van desde 0 a 500 para que vayan de 0 a 252
    distancia = map(distancia, 0, 500, 0, 252);
    // Acá le mando a processing un valor que indica que el próximo valor enviado será del sensor de distancia
    // Utilizo arbitrariamente el 254 (por eso en el map de arriba le mando como valor máximo 252)
    Serial.write(HEADER_SENSOR_DISTANCIA); 
    Serial.write(distancia);
    delay(100);
    reloj = millis();
  }

 
}
 
