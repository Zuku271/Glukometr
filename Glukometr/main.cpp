#define _CRT_SECURE_NO_WARNINGS 1
#include <systemc.h>
#include <string>
#include "SYSTEM.h"
#include "Glucometer.h"

SYSTEM *top = NULL;
int TestBench::TestCounter = 0;
int sc_main(int argc, char* argv[])
{
	top = new SYSTEM("top");
	sc_start();

	system("PAUSE");
	return 0;
}