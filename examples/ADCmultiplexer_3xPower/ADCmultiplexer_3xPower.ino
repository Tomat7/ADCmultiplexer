/*
Power Meter for 3-phase line using analog ports to read voltage and current.
Example for ADCmultiplexer library.
*/

#include "ADCmultiplexer.h"
ADCmultiplexer PowerMeter;

int U[3];	// declare U - voltage variables.
int I[3];	// declare I - current variables.
int Pins[] = {  A0,    A1,    A2,    A3,    A6,    A7   };	// array of PINs according to sequence of variables.
int Vals[] = { &U[0], &I[0], &U[1], &I[1], &U[2], &I[2] };	// array of varialbles. ADCmultiplexer will update it on check() method.
const int qty = sizeof(Pins) / sizeof(int);

long int msMillis;

void setup()
{
	Serial.begin(115200);
	delay(300);
	PowerMeter.init(qty, Pins, Vals);
	PowerMeter.showinfo();
	PowerMeter.setshift(512);	// only ONE shift level for ALL reading ports :-(
	msMillis = millis();
	delay(200);
}

void loop()
{
	PowerMeter.check();

	if ((millis() - msMillis) > 1000)
	{
		for(int i=0; i<qty; i++)
		{
			Serial.print("Power consumption on phase ");
			Serial.print(i);
			Serial.print(": ");
			Serial.println((int)(U[i]*I[i]));
			Serial.print(" watt.");
		}
		Serial.println("+++");
		msMillis = millis();
	}
}