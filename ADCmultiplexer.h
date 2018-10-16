/*
*
*/
#ifndef ADCmultiplexer_h
#define ADCmultiplexer_h

#include "Arduino.h"

#define LIBVERSION "ADCmultiplexer_v20181015 on pin: "

class ADCmultiplexer
{
public:
	ADCmultiplexer();
	
	void init(byte numSensor, int *aPin, int *Vars);
	void init(byte numSensor, int *aPin);
	void check();
		
	static void GetADC_int() __attribute__((always_inline));  //=== Прерываниe
	
protected:
	volatile static unsigned int _cntr;
	volatile static unsigned long _Summ;
	byte nSensor_;
	int *pPin_;
	int *pVar_;
	int **ppVal_;
	int i = 0;

};

#endif