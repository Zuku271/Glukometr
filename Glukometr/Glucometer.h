#pragma once

#include <systemc.h>

SC_MODULE(Glucometer)
{
	/**
	* Input
	*/
	sc_in <bool> clock;
	sc_in <bool> reset;
	sc_in <sc_uint<16>> GlucoseLevel;
	sc_in <sc_uint<16>> InsulineLevelToInject;

	/**
	* Output
	*/
	sc_out <bool> H_ind, L_ind;
	sc_out <bool> RunPump;

	sc_out <sc_uint<8>> InsulineLevel;
	sc_out <sc_uint<16>> DispGlucoseLevel;

	void CheckGlucoseLevel();
	void SignalHighGLevel();
	void SignalLowGLevel();

	SC_CTOR(Glucometer)
	{
		SC_CTHREAD(CheckGlucoseLevel, clock.pos());
		reset_signal_is(reset, true);
	}
};

