#include <SPI.h>
#include <SD.h>

#define SSPIN 4

File myFile;

void setup() {
  Serial.begin(9600);
  Serial.print("Iniciando SD ...");
  if (!SD.begin(SSPIN)) {
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("inicializacion exitosa");
 
  myFile = SD.open("test.txt");//abrimos  el archivo 
  if (myFile) {
    Serial.println("test.txt:");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close(); //cerramos el archivo
  } else {
    Serial.println("Error al abrir el archivo");
  }
}

void loop() {
  
}
