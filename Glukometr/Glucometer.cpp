#include <systemc.h>
#include "Glucometer.h"


void Glucometer::GlucometerMain()
{
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