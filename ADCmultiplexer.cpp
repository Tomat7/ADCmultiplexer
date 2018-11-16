/*
	Вольный перевод в библиотеку мелкие доработки алгоритма - Tomat7
*/

#include "Arduino.h"
#include "ADCmultiplexer.h"
// defines for setting and clearing register bits

volatile unsigned int ADCmultiplexer::_cntr;
volatile unsigned long ADCmultiplexer::_Summ;
volatile int ADCmultiplexer::_shift;

//================= Обработка прерывания АЦП для расчета среднеквадратичного тока
ISR(ADC_vect) {
	ADCmultiplexer::GetADC_int();
}

ADCmultiplexer::ADCmultiplexer()
{
}

void ADCmultiplexer::init(byte qtySensor, int *aPin, int *Vars)
{  
	pPin_ = aPin;
	pVar_ = Vars;
	_qty = qtySensor;
	// настойка АЦП
	ADMUX = _BV(REFS0) | (*pPin_ - 14);
	ADCSRA = B11101111; //Включение АЦП
	ACSR = (1 << ACD);
	_Summ=0;		// ??
	_shift=0;
	i=0;
}

void ADCmultiplexer::check()
{	
	if (_cntr == 1024)
	{	
		_Summ >>= 10;
		ppVal_ = *(pVar_+i);
		*ppVal_ = int(sqrt(_Summ));
		i++;
		if (i == _qty) i = 0;
		ADMUX = _BV(REFS0) | (*(pPin_+i) - 14);

		_Summ = 0;
		//cli();			// так в умных интернетах пишут, возможно это лишнее - ** и без этого работает **
		_cntr = 1050;		// сбросим счетчик в "кодовое" значение 
		//sei();
	}
	return;
}

void ADCmultiplexer::GetADC_int() //__attribute__((always_inline))
{
	unsigned long adcData = 0; //мгновенные значения 
	byte An_pin = ADCL;
	byte An = ADCH;
	if (_cntr < 1024)
	{
		adcData = ((An << 8) + An_pin) - _shift;
		adcData *= adcData;
		_Summ += adcData;                   
		_cntr++;
	}
	if (_cntr == 1050) _cntr = 0;
	return;
}


void ADCmultiplexer::showinfo()
{
	Serial.print(F(LIBVERSION));
	for (int y=0; y<_qty; y++)
	{
		Serial.print("A");
		Serial.print(*(pPin_+y));
		if (y<(_qty-1)) Serial.print(", ");
		else Serial.print(".");
	}

}

void ADCmultiplexer::setshift(int Shift)
{
	_shift = Shift;
}
