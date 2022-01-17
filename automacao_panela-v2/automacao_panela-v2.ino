#include <LCDIC2.h>


#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>


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
#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2

// Portas Analógicas
#define Potenciometro A0
LCDIC2 lcd(0x27, 16, 2);

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

 sensors.begin();
 Serial.begin(9600);

 lcd.begin();
 lcd.print("Iniciando - v2");
 delay(3000);
 lcd.clear();

}

float getTemperature() {  
  sensors.requestTemperatures();
  Celsus = sensors.getTempCByIndex(0);
  return Celsus;
}

float setTemperature() {
  return float(analogRead(Potenciometro)/10);
}

void show_lcd(String stCelsus, String stTemp) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Mosto");
  lcd.setCursor(11, 0);
  lcd.print("Temp.");

  lcd.setCursor(0, 1);
  lcd.print(stCelsus);
  
  lcd.setCursor(11, 1);
  lcd.print(stTemp);

}

void loop() {
  float celsus = 0;
  float setTemp = 0;
  int controle = 0;   //Tempo que a resistência ficará desligada esperando a temperatura abaixar
  
  // put your main code here, to run repeatedly:
  celsus = getTemperature();
  setTemp = setTemperature();

  String strCelsus = String(celsus, 2);
  String strTemp = String(setTemp);

  show_lcd(strCelsus, strTemp);

  // verifica se a Resistência deveria estar ligada ou não
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


  //verifica se a bomba deveria estar ligada ou não
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

     celsus = getTemperature();
     setTemp = setTemperature();

     String strCelsus = String(celsus, 2);
     String strTemp = String(setTemp);

     show_lcd(strCelsus, strTemp);

     while ((celsus + 0.55) < setTemp ) {
            digitalWrite(LedTemperatura, LOW);
            digitalWrite(ReleResistencia, HIGH);
            digitalWrite(LedResistencia, HIGH);

            celsus = getTemperature();

            String strCelsus = String(celsus, 2);
     
            show_lcd(strCelsus, strTemp);

            Serial.println(celsus);
            Serial.println(setTemp);

            delay(150);


            if (celsus >= setTemp - 2) {
              delay(6500); // fica 6.5 segundos ligado
              digitalWrite(ReleResistencia, LOW);
              digitalWrite(LedResistencia, LOW);
              delay(4500); // fica 5 segundos desligado
            }
      }

   digitalWrite(LedTemperatura, HIGH);
   
   } else {
      digitalWrite(LedTemperatura, LOW);
      digitalWrite(ReleResistencia, LOW);                
    }
  
}
