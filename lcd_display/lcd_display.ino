#include <LiquidCrystal.h> // declara a utiliza??o da biblioteca LiquidCrystal

#define Luz_Fundo  7

//cria um objeto tipo LiquidCrystal que chamei de "lcd" nos pinos citados:
LiquidCrystal lcd(0x27, 11, 5, 4, 3, 2);

void setup()
{
lcd.begin(16, 2); // Iniciando o objeto "lcd" de 2 linhas e 16 colunas
pinMode(Luz_Fundo,OUTPUT); //define o pino como sa?da
digitalWrite(Luz_Fundo,HIGH); // Liga a luz do display.
Serial.begin(115200);
}

void loop()
{

  lcd.clear();          //limpa o display do LCD.     
  lcd.print("Oi!!! ");  //imprime a string no display do LCD.
  Serial.println("Oi!!! ");
  delay(2000);                 
   
     
  lcd.setCursor(0,1);   //posiciona cursor na coluna 0 linha 1 do LCD
  lcd.print("Tudo Bem???"); //imprime a string no display do LCD.
  Serial.println("Tudo Bem???");
  delay(2000);    
   
  lcd.clear();
  lcd.print("Quer aprender");
  Serial.println("Quer aprender");
  lcd.setCursor(0,1);
  lcd.print("este projeto?");
  Serial.println("este projeto?");
  delay(4000); 
   
  lcd.clear();
  lcd.print("www.ComoFazerAsCoisas.com.br");
  Serial.println("www.ComoFazerAsCoisas.com.br");
  delay(1000);
   
  //Rolando o display para a esquerda 12 vezes
  for (int i = 0; i < 12; i++) {
    lcd.scrollDisplayLeft();
    delay(600);
  }
   
  delay(1000);
  
}
