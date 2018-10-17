/*
Three analog ports reading example
*/

#include "ADCmultiplexer.h"
ADCmultiplexer AnalogMulti;

int Temperature, Pressure, Voltage, WindSpeed;                  // declare variables which will contain data.
int Pins[] = { A0,           A1,        A2,       A3         };	// array of PINs according to sequence of variables.
int Vals[] = { &Temperature, &Pressure, &Voltage, &WindSpeed };	// array of varialbles. ADCmultiplexer will update it on check() method.
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
		Serial.println(WindSpeed);
		Serial.println("+++");
		msMillis = millis();
	}
}