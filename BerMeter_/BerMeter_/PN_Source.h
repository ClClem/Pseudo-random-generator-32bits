#pragma once
#include <cstdint>
#include <iostream>

using namespace std;

class PN_Source
{
	//Linear Feedback shift Register
	// is a lineare shift register in which each register contiains a bit we take the 
	// last cell and take the output and used as feedback and summed with the output
	// of some register
	// we can multiply the output for 0 or 1 to e
private:
	int _cnt;
	int _cycles;
	int _degree;
	uint32_t _initialState;
	uint32_t _endState;
	uint32_t _polinomialFunction[29]; // 0 and 1 bit is not a possible choice
public:
	PN_Source();
	PN_Source(int num, uint32_t state);
	~PN_Source();

	void setDegree(int input);
	void setState(uint32_t hex);
	void Generate();
	uint32_t shift(uint32_t hex);
	uint32_t getEndState();
};

