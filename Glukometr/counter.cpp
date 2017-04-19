#include "counter.h"

void counter::count()
{
	if (reset.read())
	{
		if (enable.read())
		{
			if (c_up.read())
			{
				NumberOfCounts = NumberOfCounts + 1;
				cout << "Incremented counter " << NumberOfCounts << endl;
			}
			else if (c_down.read())
			{
				NumberOfCounts = NumberOfCounts - 1;
				cout << "Decremented counter " << NumberOfCounts << endl;
			}
		}
	}
	else
	{
		NumberOfCounts = 0;
		cout << "Reset counter " << endl;
	}
	out.write(NumberOfCounts);
}