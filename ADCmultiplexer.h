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
	void check();
	int Value;

	//float Press_kPa;			// раскоментировать если нужны килоПаскали с плавающей точкой
	//uint16_t ADCperiod;		// DEBUG!! убрать
	
	//=== Прерываниe
	static void GetADC_int() __attribute__((always_inline));
	
protected:
	volatile static unsigned int _cntr;
	volatile static unsigned long _Summ;
	byte nSensor_;
	int *pPin_;
	int *pVar_;
	int **ppVal_;
	int pin_;
	int val_;
	int i = 0;

	//unsigned long _ADCmillis;			// DEBUG!! убрать
};

#endif
