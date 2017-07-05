#pragma once
#include <systemc.h>
#include "Glucometer.h"
#include <ctime>

SC_MODULE(TestBench)
{
	static int TestCounter;
	/*
	Inputs
	*/
	sc_in <bool> H_ind, L_ind;
	sc_in <bool> RunPump;
	sc_in <sc_uint<8>> InsulineLevel;
	sc_in <sc_uint<16>> DispGlucoseLevel;
	sc_in <bool> clock;

	/*
	Outputs
	*/
	sc_out <bool> reset;
	sc_out <sc_uint<16>> GlucoseLevel;
	sc_out <sc_uint<16>> InsulineLevelToInject;

	void source();
	void sink();

	SC_CTOR(TestBench)
	{
		SC_CTHREAD(source, clock.pos());
		SC_CTHREAD(sink, clock.neg());
		//srand(time(NULL));
	}
};