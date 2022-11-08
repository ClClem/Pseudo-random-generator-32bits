#pragma once
#include <stdio.h>
class BerMeter
{
public:
	BerMeter();
	~BerMeter();

	//! Set the BER parameters
	void SetParameters(
		const int delay,	//!< Delay of second stream 
		const int n = 30	//!< Number of errors to declare realiable results
	);

	//! Compare two bit streams. Returns 1 if errors are present
	int Run(
		const int sizein,		//!< Number of compared bits. 
		const int* ref,			//!< First stream (source).
		const int* decoded		//!< Second bit stream (decoded).
	);

	bool IsReliable();	//!< Return true if enough bits or frame errors have been counted.
	void Reset();		//!< Reset the error counters

	//! Display the BER statistics on specified output.
	void Display(FILE* stream = stdout //!< Output stream
	);

	//! Display the BER statistics on a single line of the specified output.
	void Display_on_Line(FILE* stream = stdout);

private: // Place here variable of the class
	int nerr;		//!< Number of counted errors
	int nbits;	    //!< Number of counted bits
	int delay;      //!< Length of delay line
	int nmin;       //!< Minimum number of error to declare reliable the measure

	int* line;		//! delay line
	int  pointer;	//! Pointer within the delay line
	bool count;		//! Flag for starting measurements
	bool start;
};
