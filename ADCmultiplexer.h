/*
*
*/
#ifndef ADCmultiplexer_h
#define ADCmultiplexer_h

#include "Arduino.h"

#define LIBVERSION "ADCmultiplexer_v20181116 uses pins: "

class ADCmultiplexer
{
public:
	ADCmultiplexer();

	//void init(byte numSensor, int *aPin);
	void init(byte qtySensor, int *aPin, int *Vars);
	void check();
	void showinfo();
	void setshift(int Shift);
	
	static void GetADC_int() __attribute__((always_inline));  //=== Прерываниe
	
protected:
	volatile static unsigned int _cntr;
	volatile static unsigned long _Summ;
	volatile static int _shift;
	
	byte _qty;
	int *pPin_;
	int *pVar_;
	int **ppVal_;
	int i;
	
};

#endif
