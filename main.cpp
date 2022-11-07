#include "PN_source.h"
#include "BerMeter.h"

int main() {
	int degree = 0;
	uint32_t startingState = 0x0;
	bool flag = false;
	PN_Source source;
	cout << "Insert a number for the degree of the polynomial between 2 and 32 and a starting state of 32bits\n";
	cin >> degree;
	while (degree < 0 || degree > 32) {
		cout << "Insert a valid number\n";
		cout << "Press s to break\n";
		if (degree == 's')
			return 1;
		cin >> degree;
	}
	cin >> startingState;
	source.setState(startingState);
	source.setDegree(degree);
	source.Generate();
	cout << source.getEndState();
	return 0;
}