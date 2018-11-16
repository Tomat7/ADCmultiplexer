/*
Three analog ports reading example
*/

#include "ADCmultiplexer.h"
ADCmultiplexer AnalogMulti;

int U[3];	// declare U - voltage variables which will contain data.
int I[3];	// declare I - current variables which will contain data.
int Pins[] = {  A0,    A1,    A2,    A3,    A6,    A7   };	// array of PINs according to sequence of variables.
int Vals[] = { &U[0], &I[0], &U[1], &I[1], &U[2], &I[2] };	// array of varialbles. ADCmultiplexer will update it on check() method.
const int qty = sizeof(Pins) / sizeof(int);

long int msMillis;

void setup()
{
	Serial.begin(115200);
	delay(300);
	AnalogMulti.init(qty, Pins, Vals);
	AnalogMulti.showinfo();
	AnalogMulti.setshift(512);
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