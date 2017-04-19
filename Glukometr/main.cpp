#define _CRT_SECURE_NO_WARNINGS 1
#include <systemc.h>
#include "counter.h"


int sc_main(int argc, char* argv[])
{
	sc_signal <bool> c_up, c_down;
	sc_signal <bool> enable, clock, reset;

	sc_signal <sc_uint<8>> input;
	int i;

	/**
	* Connect to DUT
	*/
	counter FirstCounter("Counter");

	FirstCounter.c_up(c_up);
	FirstCounter.c_down(c_down);
	FirstCounter.enable(enable);
	FirstCounter.clk(clock);
	FirstCounter.reset(reset);

	FirstCounter.out(input);

	// Open VCD file
	sc_trace_file *wf = sc_create_vcd_trace_file("counter");
	// Dump the desired signals
	sc_trace(wf, clock, "clock");
	sc_trace(wf, reset, "reset");
	sc_trace(wf, enable, "enable");
	sc_trace(wf, input, "count");

	// Initialize all variables
	reset = 1;       // initial value of reset
	enable = 0;      // initial value of enable
	c_up = 1;
	c_down = 0;
	
	for (i = 0; i<5; i++) {
		clock = 0;
		sc_start();
		clock = 1;
		sc_start();
	}
	reset = 0;    // Assert the reset
	cout << "@" << sc_time_stamp() << " Asserting reset\n" << endl;
	for (i = 0; i<10; i++) {
		clock = 0;
		sc_start();
		clock = 1;
		sc_start();
	}
	reset = 1;    // De-assert the reset
	cout << "@" << sc_time_stamp() << " De-Asserting reset\n" << endl;
	for (i = 0; i<5; i++) {
		clock = 0;
		sc_start();
		clock = 1;
		sc_start();
	}
	cout << "@" << sc_time_stamp() << " Asserting Enable\n" << endl;
	enable = 1;  // Assert enable
	for (i = 0; i<20; i++) {
		clock = 0;
		sc_start();
		clock = 1;
		sc_start();
	}
	cout << "@" << sc_time_stamp() << " De-Asserting Enable\n" << endl;
	enable = 0; // De-assert enable

	cout << "@" << sc_time_stamp() << " Terminating simulation\n" << endl;
	sc_close_vcd_trace_file(wf);

	system("PAUSE");
	return 0;
}