#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,8,2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hola mun"); // Mensaje a despegar
  lcd.setCursor(0,1);
  lcd.print("do!!"); // Mensaje a despegar
  
  delay(3000);
}

void loop() { 
  
  /*for(int c=0;c<15;c++){
    lcd.scrollDisplayLeft();
    delay(400);
  }
  for(int c=0; c<15;c++){
  lcd.scrollDisplayRight();
  delay(400); 
  }*/
}
