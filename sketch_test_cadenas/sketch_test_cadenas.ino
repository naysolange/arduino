
#define MAXIMA_LONGITUD_CADENA 65

 const char arreglo1[][MAXIMA_LONGITUD_CADENA] = {"Me gusta mirarte ser", "Es posible enamorarse de dos", "No puedo aguantar mas", "Quisiera ser un gatito chiquito mimado de departamento", "Dejar de escapar de mí", "Somos lo que somos", "A veces me siento ínfima","Pórtense mal pero háganlo bien","Estar en paz conmigo misma","Algo habrás hecho"};
 const char arreglo2[][MAXIMA_LONGITUD_CADENA] = {"2Me gusta mirarte ser", "2Es posible enamorarse de dos", "2No puedo aguantar mas", "2Quisiera ser un gatito chiquito mimado de departamento", "2Dejar de escapar de mí"};
 const char arreglo3[][MAXIMA_LONGITUD_CADENA] = {"3Me gusta mirarte ser", "3Es posible enamorarse de dos", "3No puedo aguantar mas", "3Quisiera ser un gatito chiquito mimado de departamento", "3Dejar de escapar de mí"};

  int longitudDelArreglo1 = sizeof(arreglo1) / sizeof(arreglo1[0]);
  int longitudDelArreglo2 = sizeof(arreglo2) / sizeof(arreglo2[0]);
  int longitudDelArreglo3 = sizeof(arreglo3) / sizeof(arreglo3[0]);


void setup() {
  Serial.begin(9600);
  
}

void mostrarVersoRandom(char arreglo[][MAXIMA_LONGITUD_CADENA], int longitudDelArreglo) {

 int posicionRandom = random(0,longitudDelArreglo);
 //Serial.println(posicionRandom);
 Serial.println(arreglo[posicionRandom]);
 delay(1000);

}

int i = 0;
void loop() {
  i++;
  
  if(i % 3 == 0) {
    mostrarVersoRandom(arreglo1, longitudDelArreglo1);
  } else if (i % 3 == 1){
    mostrarVersoRandom(arreglo2, longitudDelArreglo2);
  } else {
    mostrarVersoRandom(arreglo3, longitudDelArreglo3);
  }
  
  //mostrarVersoRandom(arreglo3, longitudDelArreglo3);

}
