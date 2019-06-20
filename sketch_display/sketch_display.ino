
// Prueba de Modulo I2C para LCD 2x16 
#include <LiquidCrystal_I2C.h> 


LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hola mundo..."); 
  delay(3000);
}

void loop() {
   
  for(int i=0; i<12; i++){
    lcd.scrollDisplayLeft();
    delay(400);
  }
  
  for(int i=0; i<12; i++){
    lcd.scrollDisplayRight();
    delay(400); 
  }
  
}
