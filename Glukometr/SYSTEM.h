#pragma once
#include <systemc.h>
#include "Glucometer.h"
#include "testbench.h"

SC_MODULE(SYSTEM)
{
	Glucometer *glk;
	TestBench *tb;

	sc_clock clock_sig;

	sc_signal <bool> reset_sig;
	sc_signal <bool> H_ind_sig, L_ind_sig;
	sc_signal <bool> RunPump_sig;

	sc_signal <sc_uint<16>> GlucoseLevel_sig;
	sc_signal <sc_uint<16>> InsulineLevelToInject_sig;
	sc_signal <sc_uint<16>> DispGlucoseLevel_sig;

	sc_signal <sc_uint<8>> InsulineLevel_sig;

	SC_CTOR(SYSTEM) : clock_sig("clock_sig", 2, SC_SEC)
	{
		tb = new TestBench("tb");
		tb->clock(clock_sig);
		tb->reset(reset_sig);
		tb->RunPump(RunPump_sig);
		tb->H_ind(H_ind_sig);
		tb->L_ind(L_ind_sig);
		tb->GlucoseLevel(GlucoseLevel_sig);
		tb->InsulineLevelToInject(InsulineLevelToInject_sig);
		tb->DispGlucoseLevel(DispGlucoseLevel_sig);
		tb->InsulineLevel(InsulineLevel_sig);

		glk = new Glucometer("glk");
		glk->clock(clock_sig);
		glk->reset(reset_sig);
		glk->RunPump(RunPump_sig);
		glk->H_ind(H_ind_sig);
		glk->L_ind(L_ind_sig);
		glk->GlucoseLevel(GlucoseLevel_sig);
		glk->InsulineLevelToInject(InsulineLevelToInject_sig);
		glk->DispGlucoseLevel(DispGlucoseLevel_sig);
		glk->InsulineLevel(InsulineLevel_sig);

	}

	~SYSTEM()
	{
		delete tb, glk;
	}
};