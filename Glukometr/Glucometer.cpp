#include <systemc.h>
#include "Glucometer.h"


void Glucometer::CheckGlucoseLevel()
{
	if (GlucoseLevel.read() >= 120)
	{
		SignalHighGLevel();
	}
	else if (GlucoseLevel.read() < 80)
	{
		SignalLowGLevel();
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