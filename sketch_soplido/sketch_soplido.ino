
#define PIN_LED A0                // High side of the resistor
#define PIN_MEDICION A6           // Low side of resistor and anode of LED
#define DIFERENCIA_MINIMA 5.0           
#define CANTIDAD_SENSADA 10
long int dataSensada[CANTIDAD_SENSADA];
long int dataSensada2[CANTIDAD_SENSADA];
int j = 0;
int k = 0;

void setup() {
  Serial.begin(230400);                     
  pinMode(PIN_MEDICION, INPUT);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, HIGH);   
}

void loop() {

  long int sum = 0;

  // Suma 256 lecturas para reducir el ruido
  for (int i = 0; i < 256; i++) {
    sum = sum + analogRead(PIN_MEDICION);
  }

  // Guarda primero 10 mediciones, luego otras 10
  if(j < CANTIDAD_SENSADA) {
    dataSensada[j] = sum; 
    j++;
  } else {
    dataSensada2[k] = sum; 
    k++;
  }

  // Si ya están llenos los 2 arrays saca el promedio de cada uno
  if(j == CANTIDAD_SENSADA && k == CANTIDAD_SENSADA) {
    float promedio1 = promedioSuma(dataSensada);
    float promedio2 = promedioSuma(dataSensada2);
    Serial.println(promedio1);

    // Si la diferencia entre el promedio de los segundos valores leídos es mayor a 
    // un X valor entonces quiere decir que hubo una variación (alguien hizo un soplido)
    // entonces apago y prendo el led con un delay en medio
    if(promedio2 - promedio1 > DIFERENCIA_MINIMA){
        digitalWrite(PIN_LED, LOW);
        delay(3000);                            
        digitalWrite(PIN_LED, HIGH);
    }
    j = 0;
    k = 0;
  }

}

float promedioSuma(long int dataSensada[]) {
   
   long int sum = 0;
   
   for (int i = 0; i < CANTIDAD_SENSADA; i++) {
    sum = sum + dataSensada[i]; 
   }

   return sum/CANTIDAD_SENSADA;
}
