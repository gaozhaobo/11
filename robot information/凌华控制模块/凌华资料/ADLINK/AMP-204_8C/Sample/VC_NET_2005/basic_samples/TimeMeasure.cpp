#include "stdafx.h"
#include <windows.h>
#include "TimeMeasure.h"

static LARGE_INTEGER gFreq;
static LARGE_INTEGER gOverHead;

static LARGE_INTEGER gStart;
static LARGE_INTEGER gEnd;

void J_initial_tm()
{
	QueryPerformanceFrequency( &gFreq );
	
	J_start_measure();
	J_end_measure();

	gOverHead.QuadPart = gStart.QuadPart - gEnd.QuadPart;
}

void J_start_measure()
{
	QueryPerformanceCounter( &gStart );
}

void J_end_measure()
{
	QueryPerformanceCounter( &gEnd );
}

double J_get_duration()
{
	double itv_ms;

	itv_ms = (double)( (gEnd.QuadPart - gStart.QuadPart) - gOverHead.QuadPart ) 
				           * 1000.0 / (double)gFreq.QuadPart;
	return itv_ms;
}