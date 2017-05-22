#define _CRT_SECURE_NO_WARNINGS 1
#include <systemc.h>
#include <string>
#include "counter.h"
#include "Glucometer.h"


int sc_main(int argc, char* argv[])
{
	sc_signal <bool> clock, reset, enable;
	sc_signal <bool> H_ind, L_ind;
	sc_signal <bool> RunPump;

	sc_signal <sc_uint<16>> GlucoseLevel;
	sc_signal <sc_uint<16>> InsulineLevelToInject;
	sc_signal <sc_uint<16>> DispGlucoseLevel;
	
	sc_signal <sc_uint<8>> InsulineLevel;


	/**
	* Connect to DUT
	*/

	Glucometer glk("Glucometer");

	glk.GlucoseLevel(GlucoseLevel);
	glk.InsulineLevelToInject(InsulineLevelToInject);
	glk.clock(clock);
	glk.reset(reset);
	glk.H_ind(H_ind);
	glk.L_ind(L_ind);
	glk.RunPump(RunPump);
	glk.DispGlucoseLevel(DispGlucoseLevel);
	glk.InsulineLevel(InsulineLevel);

	
	// Open VCD file
	sc_trace_file *wf = sc_create_vcd_trace_file("glucose");
	// Dump the desired signals
	sc_trace(wf, clock, "clock");

	

	// Initialize all variables
	reset = 1;       // initial value of reset
	clock = 0;
	GlucoseLevel = 100;

	sc_trace(wf, reset, "reset");
	sc_trace(wf, enable, "GlucoseLevel");
	sc_trace(wf, InsulineLevelToInject, "InsulineLevelToInject");

	// Initialize all variables
	reset = 1;       // initial value of reset
	enable = 0;      // initial value of enable
	GlucoseLevel = 40;
	InsulineLevelToInject = 10;
	
	for (int i = 0; i<5; i++)
	{
		clock = 0;
		sc_start();
		clock = 1;
		sc_start();
	}
	reset = 0;    // Assert the reset
	cout << "@" << sc_time_stamp() << " Asserting reset\n" << endl;
	for (int i = 0; i < 10; i++)
	{
		clock = 0;
		sc_start();
		clock = 1;
		sc_start();
	}
	reset = 1;    // De-assert the reset
	cout << "@" << sc_time_stamp() << " De-Asserting reset\n" << endl;
	for (int i = 0; i < 5; i++)
	{
		clock = 0;
		sc_start();
		clock = 1;
		sc_start();
	}


	/*----*/
	cout << "@" << sc_time_stamp() << " Asserting GlucoseLevel\n" << endl;
	GlucoseLevel = 500;
	for (int i = 0; i<10; i++) {
		clock = 0;
		sc_start();
		clock = 1;
		sc_start();
	}
	GlucoseLevel = 10;    // De-assert Glucose Level
	cout << "@" << sc_time_stamp() << " De-Asserting GlucoseLevel\n" << endl;
	for (int i = 0; i<5; i++) {
		clock = 0;
		sc_start();
		clock = 1;
		sc_start();
	}
	/*----*/


	cout << "@" << sc_time_stamp() << " Terminating simulation\n" << endl;
	sc_close_vcd_trace_file(wf);
	
	system("PAUSE");
	return 0;
}