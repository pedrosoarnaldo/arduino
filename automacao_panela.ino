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

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  Celsus = sensors.getTempCByIndex(0);
  Serial.println(Celsus);
  delay(1000);

}
