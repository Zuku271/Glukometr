#include <systemc.h>
#include "Glucometer.h"


void Glucometer::CheckGlucoseLevel()
{
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