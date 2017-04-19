#include <systemc.h>
#include "Glucometer.h"


void Glucometer::CheckGlucoseLevel()
{
	if (GlucoseLevel.read() >= 120)
	{
		H_ind.write(1);
	}
	else if (GlucoseLevel.read() < 80)
	{
		L_ind.write(1);
	}
}
