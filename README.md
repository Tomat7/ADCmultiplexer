# AnalogMultiRead

Continuously reading ADC value from *SEVERAL* pins using **Free-Running** mode and interrupt - ie working in background.  
The library switch between analog pins in free-running mode and returns ~~average~~ [RMS](https://en.wikipedia.org/wiki/Root_mean_square "Google's RMS definition") value of last measurement cycle.  
Each cycle doing 1024 measurement for each pin/port - it takes ~100 ms per port.  
So, it is necessary to use periodically `check()` method to update value and switching to next pin/port.  
See `/example` for details.

See also https://github.com/Tomat7/ADCmulti - works similar but easy to use and returns *average* value. (I thinks so :-)

