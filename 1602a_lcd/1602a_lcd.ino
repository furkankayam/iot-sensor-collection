#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C adresini belirleyin (genellikle 0x27 veya 0x3F olur)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.backlight(); // Arka ışığı açar
  lcd.setCursor(3, 1); // 3. kolon 1. satir
  lcd.print("Furkan!");
}

void loop() {
}