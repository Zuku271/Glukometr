#pragma once
//-----------------------------------------------------
// Design Name : 
// File Name   : 
// Function    : 
// Coder       : 
//-----------------------------------------------------
#include "systemc.h"

SC_MODULE(counter)
{
	//-----------Input Ports---------------
	sc_in <bool> c_up, c_down;
	sc_in <bool> enable, clk, reset;
	//-----------Output Ports---------------
	sc_out   <sc_uint<8> > out;
	//------------Internal Variables--------
	sc_uint<8>  NumberOfCounts;

	//-------------Code Starts Here---------
	void count();

	SC_CTOR(counter) 
	{
		cout << "Executing new" << endl;
		SC_METHOD(count);
		sensitive << reset;
		sensitive << clk.pos();
	}

};