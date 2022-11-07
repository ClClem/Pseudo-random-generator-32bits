#include "PN_Source.h"

PN_Source::PN_Source() {
	_degree= 0;
	_initialState = 0;
	_endState = 0;
	_cycles = 2; //to modify if we want more cycles of generation


	_polinomialFunction[0] = 0x3;
	_polinomialFunction[1] = 0x6;
	_polinomialFunction[2] = 0xC;
	_polinomialFunction[3] = 0x14;
	_polinomialFunction[4] = 0x30;
	_polinomialFunction[5] = 0x60;
	_polinomialFunction[6] = 0xB4;
	_polinomialFunction[7] = 0x110;
	_polinomialFunction[8] = 0x240;
	_polinomialFunction[9] = 0x500;
	_polinomialFunction[10] = 0xE08;
	_polinomialFunction[10] = 0x1C80;
	_polinomialFunction[11] = 0x3802;
	_polinomialFunction[12] = 0x6000;
	_polinomialFunction[13] = 0xD008;
	_polinomialFunction[14] = 0x12000;
	_polinomialFunction[15] = 0x20400;
	_polinomialFunction[16] = 0x72000;
	_polinomialFunction[17] = 0x90000;
	_polinomialFunction[18] = 0x140000;
	_polinomialFunction[19] = 0x300000;
	_polinomialFunction[20] = 0x420000;
	_polinomialFunction[21] = 0xE10000;
	_polinomialFunction[22] = 0x1200000;
	_polinomialFunction[23] = 0x2000023;
	_polinomialFunction[24] = 0x9000000;
	_polinomialFunction[25] = 0x14000000;
	_polinomialFunction[26] = 0x20000029;
	_polinomialFunction[27] = 0x48000000;
	_polinomialFunction[28] = 0x80200003;
}

PN_Source::PN_Source(int num, uint32_t state) {
	_degree = num;
	_initialState = state;
	_endState = 0;
	_cycles = 16;
	_polinomialFunction[0] = 0x3;
	_polinomialFunction[1] = 0x6;
	_polinomialFunction[2] = 0xC;
	_polinomialFunction[3] = 0x14;
	_polinomialFunction[4] = 0x30;
	_polinomialFunction[5] = 0x60;
	_polinomialFunction[6] = 0xB4;
	_polinomialFunction[7] = 0x110;
	_polinomialFunction[8] = 0x240;
	_polinomialFunction[9] = 0x500;
	_polinomialFunction[10] = 0xE08;
	_polinomialFunction[10] = 0x1C80;
	_polinomialFunction[11] = 0x3802;
	_polinomialFunction[12] = 0x6000;
	_polinomialFunction[13] = 0xD008;
	_polinomialFunction[14] = 0x12000;
	_polinomialFunction[15] = 0x20400;
	_polinomialFunction[16] = 0x72000;
	_polinomialFunction[17] = 0x90000;
	_polinomialFunction[18] = 0x140000;
	_polinomialFunction[19] = 0x300000;
	_polinomialFunction[20] = 0x420000;
	_polinomialFunction[21] = 0xE10000;
	_polinomialFunction[22] = 0x1200000;
	_polinomialFunction[23] = 0x2000023;
	_polinomialFunction[24] = 0x9000000;
	_polinomialFunction[25] = 0x14000000;
	_polinomialFunction[26] = 0x20000029;
	_polinomialFunction[27] = 0x48000000;
	_polinomialFunction[28] = 0x80200003;
}

void PN_Source::setState(uint32_t num) {
	_initialState = num;
}

void PN_Source::setDegree(int num) {
	_degree = num;
}
void PN_Source::Generate() {
	uint32_t xorOp = 0;
	uint32_t tmp = _initialState;
	for (int i = 0;i < _cycles;i++) {
		_endState = (tmp & 1) ?										shift((_polinomialFunction[_degree - 2] ^ (			(tmp-1)					&				_polinomialFunction[_degree - 2])))																				+ shift(tmp & ~_polinomialFunction[_degree - 2])												: shift(tmp);
		//	checks if the first bit of the initialState is = 1, if true:										[(discarding first bit of tmp) AND operation with the choosen feedback function] in this way i'm just doing the next XOR (^) operation between the bits i need. ADDING the result of the XOR to the initialState shifted in which i've removed the unwanted bits. ELSE it's just a shift
		tmp = _endState;
	}
}

uint32_t PN_Source::shift(uint32_t hex) {
	if (hex & 0x1) {
		hex = hex >> 1;
		hex += 0x80000000;
	}
	else {
		hex = hex >> 1;
	}
	return hex;
}

uint32_t PN_Source::getEndState() {
	return this->_endState;
}

PN_Source::~PN_Source() {
}