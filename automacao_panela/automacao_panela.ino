#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 8

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celsus = 0;

void setup() {
  // put your setup code here, to run once:
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

  Serial.println(celsus);
  Serial.println(setTemp);
  
  delay(1000);

}
