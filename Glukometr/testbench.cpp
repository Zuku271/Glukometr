#include <systemc.h>
#include "testbench.h"

void TestBench::source()
{
	/*
	Reset
	*/
	GlucoseLevel.write(0);
	reset.write(1);
	wait();
	reset.write(0);

	sc_uint<16> tmp = 0;

	/*
	Send
	*/
	for (int i = 0; i < 64; i++)
	{
		if (i > 23 && i < 29)
		{
			tmp = 10;
		}
		else
		{
			tmp = 170;
		}
		tmp = 10*i;
		GlucoseLevel.write(tmp);
		wait();
	}
}

void TestBench::sink()
{
	sc_uint<16> indata;
	bool HighGLevel;
	bool LowGLevel;

	/*
	Read
	*/
	for (int i = 0; i < 64; i++)
	{
		indata = GlucoseLevel.read();
		HighGLevel = H_ind.read();
		LowGLevel = L_ind.read();
		wait();

		cout << i << ":\t" << indata.to_int() << ":\t"
			<< HighGLevel << ":\t" << LowGLevel
			<< endl;
	}
	TestCounter = TestCounter + 1;
	sc_stop();
}