#include "PN_source.h"
#include "BerMeter.h"

int main() {
	uint32_t tmp= 0x1;
	tmp = tmp << 1;
	int degree = 0;
	uint32_t startingState = 0x0;
	bool flag = false;
	PN_Source source;
	cout << "Insert a number for the degree of the polynomial between 2 and 32 and a starting state with the same number of bits as the degree\n";
	cin >> degree;
	while (degree < 2 || degree > 32) {
		cout << "Insert a valid number (between 2 and 32)\n";
		cout << "Press s to break\n";
		if (degree == 's')
			return 1;
		cin >> degree;
	}
	cin >> startingState;
	source.setState(startingState);
	source.setDegree(degree);
	source.Generate();
	cout << source.getEndState() << ": endstate\n";
	return 0;
}