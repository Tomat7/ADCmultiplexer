# AnalogMultiRead

Continuously reading ADC value from SEVERAL pins using Free-Running mode and interrupt.  
The library switch between analog pins in free-running mode and returns average of last measurements.  
Each cycle doing 1024 measurement for each pin/port - it takes ~100 ms per port. 
So, it is necessary to use `check()` method to update value and switch to next pin/port.  

See also https://github.com/Tomat7/ADCmulti - works by the same princinples but easy to use. (I thinks so :-)

