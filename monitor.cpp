#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

int vitalsOk(float temperature, float pulseRate, float spo2) {
	return Temp_Check(temperature) && PulseRate_Check(pulseRate) && SpO2_Check(spo2);
}

int PulseRate_Check(float pulseRate)
{
	if(pulseRate < 60 || pulseRate > 100)
	{
		Call_Sleep_Print();
		return 0;
	}
	return 1;
}

int SpO2_Check(float spo2)
{
	if(spo2 < 90)
	{
		Call_Sleep_Print();	
		return 0;
	}
	return 1;
}

int Temp_Check(float temperature)
{	
	if(temperature > 102 || temperature < 95)
	{
		Call_Sleep_Print();
		return 0;
	}
	return 1;
}

void Call_Sleep_Print()
{
	for (int i = 0; i < 6; i++) {
		cout << "\r* " << flush;
		sleep_for(seconds(1));
		cout << "\r *" << flush;
		sleep_for(seconds(1));
	}
}
