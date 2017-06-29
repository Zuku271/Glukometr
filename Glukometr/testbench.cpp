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

	sc_uint<16> tmp;

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
		GlucoseLevel.write(tmp);
		wait();
	}
}

void TestBench::sink()
{
	sc_uint<16> indata;

	/*
	Read
	*/
	for (int i = 0; i < 64; i++)
	{
		indata = DispGlucoseLevel.read();
		wait();

		cout << i << " :\t" << indata.to_int() << endl;
	}
	sc_stop();
}