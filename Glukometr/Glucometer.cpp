#include <systemc.h>
#include "Glucometer.h"


void Glucometer::GlucometerMain()
{
<<<<<<< HEAD
	//reset
	DispGlucoseLevel.write(0);
	InsulineLevel.write(0);
	H_ind.write(0);
	L_ind.write(0);
	RunPump.write(0);

	wait();
	
	//main
	while (1)
	{
		if (GlucoseLevel.read() >= 120)
		{
			H_ind.write(1);
		}
		else if (GlucoseLevel.read() < 80)
		{
			L_ind.write(1);
=======
	sc_uint<16> GLevel;

	while (1)
	{
		GLevel = GlucoseLevel.read().to_int();
		if (GLevel >= 120)
		{
			H_ind.write(1);
			L_ind.write(0);
			RunPump.write(1);
		}
		else if (GLevel < 80)
		{
			H_ind.write(0);
			L_ind.write(1);
			RunPump.write(0);
		}
		else
		{
			H_ind.write(1);
			L_ind.write(1);
			RunPump.write(0);
>>>>>>> beta
		}
		wait();
	}

}

void Glucometer::SignalHighGLevel()
{
	H_ind.write(1);
}

void Glucometer::SignalLowGLevel()
{
	L_ind.write(1);
}