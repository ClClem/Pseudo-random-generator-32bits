#include "BerMeter.h"

BerMeter::BerMeter()
{
	delay = 0;
	nmin = 0;
	nerr = 0;
	line = 0;
	count = false;
}


BerMeter::~BerMeter()
{
	delete[] line;
}

void BerMeter::SetParameters(const int delay, const int n)
{
	this->delay = delay;
	this->nmin = n;
	delete[] line;  line = 0;
	int i;
	count = true;
	if (delay > 0)
	{
		line = new int[delay];
		for (i = 0; i < delay; i++)line[i] = 0;
		pointer = 0;
		count = false;
	}
	Reset();
	start = true;
}

int BerMeter::Run(const int sizein, const int* ref, const int* decoded)
{
	int i, bit;
	for (i = 0; i < sizein; i++)
	{
		if (delay > 0)
		{
			//circular buffer
			bit = line[pointer];	//getout the data
			line[pointer] = ref[i];	//store new data
			pointer = (pointer + 1) % delay;  // Circular pointer
			//check if data is available
			if (start && pointer == 0)count = true; // Full line, Start BER measure
			if (!count)continue;
		}
		else
		{
			bit = ref[i];
		}
		nerr += bit ^ decoded[i];
		nbits++;
	}
	return nerr;
}

bool BerMeter::IsReliable()
{
	if (nerr >= nmin)return true;
	else             return false;
}

void BerMeter::Reset()
{
	nerr = nbits = 0;
}

void BerMeter::Display(FILE* stream)
{
	fprintf(stream, "BER=(%d/%d)= \t%e\n", nerr, nbits, (double)nerr / nbits);
}

void BerMeter::Display_on_Line(FILE* stream)
{
	fprintf(stream, "%d\t%d\t%e\t", nerr, nbits, (double)nerr / nbits);
}
#include "BerMeter.h"

