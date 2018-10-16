/*
  Three analog ports reading example
*/

#include "ADCmultiplexer.h"
ADCmultiplexer AnalogMulti;

int Temperature, Pressure, Voltage;
int Pins[] = {A1, A2, A3};
int Vals[] = { &Temperature, &Pressure, &Voltage };
const int numberOfSensors = sizeof(Pins) / sizeof(int);

long int msMillis;

void setup()
{
  Serial.begin(115200);
  delay(300);
  AnalogMulti.init(numberOfSensors, Pins, Vals);
  msMillis = millis();
  delay(200);
}

void loop()
{
  AnalogMulti.check();

  if ((millis() - msMillis) > 1000)
  {
    Serial.println(Temperature);
    Serial.println(Pressure);
    Serial.println(Voltage);
    Serial.println("+++");
    msMillis = millis();
  }
}
