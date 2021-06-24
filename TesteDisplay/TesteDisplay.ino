// ENGENHOCANDO
// Display LCD 20x4 com Adaptador I2C e Arduino;
// Download Biblioteca:
// https://www.arduinolibraries.info/libraries/liquid-crystal-i2-c
 
// Carrega as bibliotecas necessárias
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> // instalar liquidcrystal
 
// seta endereço do LCD como 0x27 e sendo 20 colunas e 04 linhas
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  lcd.init();       // inicializa LCD
  lcd.backlight();  // acende backlight
  //lcd.clear();      //limpa a tela (caracteres)

  // linha coluna 
  lcd.setCursor(0, 0);// endereça cursor
  lcd.print("Arnaldo");// escreve
}
 
void loop() {
  /* lcd.noBacklight();
  delay(1000);
  lcd.clear();
  lcd.backlight();
  delay(1000); */
}
