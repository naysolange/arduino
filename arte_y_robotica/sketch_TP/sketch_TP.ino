#include <LiquidCrystal_I2C.h>

#define CANTIDAD_PALABRAS 10
LiquidCrystal_I2C lcd(0x27,8,2);

//definicion de pines
const int pinMotor1 = 8;    // 28BYJ48 - In1
const int pinMotor2 = 9;    // 28BYJ48 - In2
const int pinMotor3 = 10;   // 28BYJ48 - In3
const int pinMotor4 = 11;   // 28BYJ48 - In4
 
//definicion variables
int velocidadMotor = 1000;  // variable para determinar la velocidad 
// 800 maxima - minima 1000 o mas
int contadorPasos = 0;      // contador para los pasos
int pasosPorVuelta = 4076;  // pasos para una vuelta completa
 

//secuencia media fase usar velocidadMotor = 1000
const int cantidadPasos = 8;
const int tablaPasos[8] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };

String palabras[CANTIDAD_PALABRAS] = {"escapar","sola","cuerpo", "cansada", "sentido", "harta","amor", "derecho", "poder", "dormi"};
int posicion = 0;
 
void setup()
{

  pinMode(pinMotor1, OUTPUT);
  pinMode(pinMotor2, OUTPUT);
  pinMode(pinMotor3, OUTPUT);
  pinMode(pinMotor4, OUTPUT);
  
  lcd.init();
  lcd.clear();
}
 
void loop()
{

  lcd.clear();
  lcd.noBacklight();
  
  for (int i = 0; i < pasosPorVuelta; i++){
    sentidoHorario();
    delayMicroseconds(velocidadMotor);
  }

  mostrarPalabra();
}
 
void sentidoHorario() {
  contadorPasos++;
  if (contadorPasos >= cantidadPasos) contadorPasos = 0;
  escribirSalidas(contadorPasos);
}
 
 
void escribirSalidas(int paso) {
  digitalWrite(pinMotor1, bitRead(tablaPasos[paso], 0));
  digitalWrite(pinMotor2, bitRead(tablaPasos[paso], 1));
  digitalWrite(pinMotor3, bitRead(tablaPasos[paso], 2));
  digitalWrite(pinMotor4, bitRead(tablaPasos[paso], 3));
}

void mostrarPalabra() {

  String palabraRecortada1;
  String palabraRecortada2;
  int maxCaracteresPorRenglon = 8;
  
  // Obtiene una palabra del array
  if(posicion == CANTIDAD_PALABRAS) posicion = 0;
  String palabra = palabras[posicion];
  posicion++;

  int longitudPalabra = palabra.length();

  // La libreria del display de 16x1 lo maneja como si fuera 8x2
  // por eso tengo que cortar la palabra si tiene más de 8 caracteres 
  // y pasarla al "renglón" siguiente
  if(longitudPalabra > maxCaracteresPorRenglon) {   
    palabraRecortada1 = palabra.substring(0, 8);
    palabraRecortada2 = palabra.substring(8, longitudPalabra);
  } else {
    palabraRecortada1 = palabra;
  }

  // Limpio y prendo el display
  lcd.clear();
  lcd.backlight();
  // Posiciono el cursor del primer "renglón" e imprimo
  lcd.setCursor(0,0);
  lcd.print(palabraRecortada1); 
  // Posiciono el cursor del segundo "renglón" e imprimo
  lcd.setCursor(0,1);
  lcd.print(palabraRecortada2); 
  // Espero 2 segundos para poder leer la palabra
  delay(2000);
}
