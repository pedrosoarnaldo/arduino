#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


// Portas Digitais
#define LedResistencia 13     //Laranja
#define LedTemperatura 12     //Verde
#define LedBomba 11           //Roxo
#define BotaoResistencia 10   //Preto
#define BotaoBomba 9          //Branco
#define ReleResistencia 8     //Cinza
#define ReleBomba 7           //Marrom
#define ONE_WIRE_BUS 2        //Amarelo

// DEFINIÇÕES
//#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
//#define colunas   16
//#define linhas    2

//LiquidCrystal_I2C lcd(endereco, colunas, linhas);


// Portas Analógicas
#define Potenciometro A0

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celsus = 0;

int EstadoBotaoResistencia = 0;
int EstadoBotaoBomba = 0;

void setup() {
  // put your setup code here, to run once:

 pinMode(BotaoResistencia, INPUT);
 pinMode(BotaoBomba, INPUT);

 pinMode(LedResistencia, OUTPUT);
 pinMode(LedBomba, OUTPUT);
 pinMode(LedTemperatura, OUTPUT);
 pinMode(ReleResistencia, OUTPUT);
 pinMode(ReleBomba, OUTPUT);
 
 digitalWrite(LedResistencia, LOW);
 digitalWrite(LedBomba, LOW);
 digitalWrite(LedTemperatura, LOW);
 digitalWrite(ReleBomba, LOW);

/*
  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear(); // LIMPA O DISPLAY

  lcd.print("- Ola, Mundo! -");
  delay(5000); // DELAY DE 5 SEGUNDOS
  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  lcd.print("Fim do Setup ()");
  delay(5000); // DELAY DE 5 SEGUNDOS
  
  lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY
  delay(2000); // DELAY DE 2 SEGUNDOS
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  delay(2000); // DELAY DE 2 SEGUNDOS
  
  lcd.clear(); // LIMPA O DISPLAY
  lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY
*/

 sensors.begin();
 Serial.begin(9600);

}

float getTemperature() {  
  sensors.requestTemperatures();
  Celsus = sensors.getTempCByIndex(0);
  return Celsus;
}

float setTemperature() {
  return float(analogRead(Potenciometro)/10);
}

void loop() {
  float celsus = 0;
  float setTemp = 0;
  int contDelay = 5000;   //Tempo que a resistência ficará desligada esperando a temperatura abaixar - 5 minutos
  
  // put your main code here, to run repeatedly:
  celsus = getTemperature();
  setTemp = setTemperature();

  if ((digitalRead(BotaoResistencia) == HIGH) && (EstadoBotaoResistencia == 0)) {
    EstadoBotaoResistencia = 1;
    digitalWrite(LedResistencia, HIGH);
    digitalWrite(ReleResistencia, HIGH);
  } else {
    if ((digitalRead(BotaoResistencia) == HIGH) && (EstadoBotaoResistencia == 1)) {
    digitalWrite(LedResistencia, LOW);
    digitalWrite(ReleResistencia, LOW);
    EstadoBotaoResistencia = 0;
    }
  }
 
  if ((digitalRead(BotaoBomba) == HIGH) && (EstadoBotaoBomba == 0)) {
    EstadoBotaoBomba = 1;
    digitalWrite(LedBomba, HIGH);
    digitalWrite(ReleBomba, HIGH);
  } else {
    if ((digitalRead(BotaoBomba) == HIGH) && (EstadoBotaoBomba == 1)) {
    digitalWrite(LedBomba, LOW);
    digitalWrite(ReleBomba, LOW);
    EstadoBotaoBomba = 0;
    }
  }

  Serial.println(celsus);
  Serial.println(setTemp);

  if (EstadoBotaoResistencia == 1) { 
    if (celsus >= setTemp) {
      digitalWrite(LedTemperatura, HIGH);
      digitalWrite(ReleResistencia, LOW);
      for (int i = 0; i <= contDelay; i++) {
          celsus = getTemperature();
          setTemp = setTemperature();
          Serial.println(celsus);
          Serial.println(setTemp);
        delay(1);  
      }            
    } else {
      digitalWrite(LedTemperatura, LOW);
      digitalWrite(ReleResistencia, HIGH);                
    }
  }
  
  delay(150);

/*  lcd.clear();
  lcd.print("- Ola, Mundo! -");
  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  lcd.print("Fim do Setup ()");
*/

}
