#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 8
#define BotaoResistencia 7
#define BotaoBomba 5
#define LedResistencia 6
#define LedBomba 4

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

 digitalWrite(LedResistencia, LOW);
 digitalWrite(LedBomba, LOW);
 
 sensors.begin();
 Serial.begin(9600);

}

float getTemperature() {  
  sensors.requestTemperatures();
  Celsus = sensors.getTempCByIndex(0);
  return Celsus;
}

float setTemperature() {
  return float(analogRead(A0)/10);
}

void loop() {
  float celsus = 0;
  float setTemp = 0;
  
  // put your main code here, to run repeatedly:
  celsus = getTemperature();
  setTemp = setTemperature();

  if ((digitalRead(BotaoResistencia) == HIGH) && (EstadoBotaoResistencia == 0)) {
    EstadoBotaoResistencia = 1;
    digitalWrite(LedResistencia, HIGH);
  } else {
    if ((digitalRead(BotaoResistencia) == HIGH) && (EstadoBotaoResistencia == 1)) {
    digitalWrite(LedResistencia, LOW);
    EstadoBotaoResistencia = 0;
    }
  }
 
  if ((digitalRead(BotaoBomba) == HIGH) && (EstadoBotaoBomba == 0)) {
    EstadoBotaoBomba = 1;
    digitalWrite(LedBomba, HIGH);
  } else {
    if ((digitalRead(BotaoBomba) == HIGH) && (EstadoBotaoBomba == 1)) {
    digitalWrite(LedBomba, LOW);
    EstadoBotaoBomba = 0;
    }
  }

  Serial.println(celsus);
  Serial.println(setTemp);

  if (EstadoBotaoResistencia == 1) { 
    if (celsus >= setTemp) {
      digitalWrite(LedResistencia, LOW);
      EstadoBotaoResistencia = 0;    
      // Desligar a Resistência
      
    } else {
      digitalWrite(LedResistencia, HIGH);
      EstadoBotaoResistencia = 1;
      // Ligar a Resistência        
    }

  }
  
  delay(90);
  
}
