#define _CRT_SECURE_NO_WARNINGS 1
#include <systemc.h>
#include <string>
#include "counter.h"
#include "Glucometer.h"


int sc_main(int argc, char* argv[])
{
	sc_signal <bool> clock, reset;

	sc_signal <sc_uint<16>> GlucoseLevel;
	int i;

	/**
	* Connect to DUT
	*/
	Glucometer glk("Glucometer");

	glk.clock(clock);
	glk.reset(reset);
	glk.GlucoseLevel(GlucoseLevel);
	
	// Open VCD file
	sc_trace_file *wf = sc_create_vcd_trace_file("glucose");
	// Dump the desired signals
	sc_trace(wf, clock, "clock");
	

	// Initialize all variables
	reset = 1;       // initial value of reset
	clock = 0;
	GlucoseLevel = 100;

	for (i = 0; i < 5; i++)
	{
		clock = 0;
		sc_start();
		clock = 1;
		sc_start();
	}
	reset = 0;    // Assert the reset
	cout << "@" << sc_time_stamp() << " Asserting reset\n" << endl;
	for (i = 0; i < 10; i++)
	{
		clock = 0;
		sc_start();
		clock = 1;
		sc_start();
	}
	reset = 1;    // De-assert the reset
	cout << "@" << sc_time_stamp() << " De-Asserting reset\n" << endl;
	for (i = 0; i < 5; i++)
	{
		clock = 0;
		sc_start();
		clock = 1;
		sc_start();
	}


	cout << "@" << sc_time_stamp() << " Terminating simulation\n" << endl;
	sc_close_vcd_trace_file(wf);
	
	system("PAUSE");
	return 0;
}