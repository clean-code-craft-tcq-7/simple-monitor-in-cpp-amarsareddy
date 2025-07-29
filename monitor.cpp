#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

int vitalsOk(float temperature, float pulseRate, float spo2) {
	return Temp_Check(temperature) && PluseRate_Check(pulseRate) && SpO2_Check(spo2);
}


int PluseRate_Check(float pulseRate)
{
int PulseRate_valid = 0;

	if(pulseRate < 60 || pulseRate > 100)
	{
		PulseRate_valid = 1;
		Call_Sleep_Print();
	}

return PulseRate_valid;	
}

int SpO2_Check( float spo2)
{
int SpO2_Valid = 0;
	
	if(spo2 < 90)
	{
		SpO2_Valid = 1;
		Call_Sleep_Print();	
	}
	
return SpO2_Valid;
}

int Temp_Check(float temperature)
{	
int Temp_valid = 0;
	
	if(temperature > 102 || temperature < 95)
	{
		Temp_valid = 1;
		Call_Sleep_Print();
	}
	else{}
	
return Temp_valid;
}

void Call_Sleep_Print()
{
   int i=0;
	
	for (int i = 0; i < 6; i++) {
	cout << "\r* " << flush;
	sleep_for(seconds(1));
	cout << "\r *" << flush;
	sleep_for(seconds(1));
	}
	
return 0;
}
