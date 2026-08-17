/*#include <iostream>
using namespace std;

int main() {
	int n;
	int y[4];
	int rst;

	cin >> n;

	while (true) {
		n++;
		y[0] = n / 1000;
		y[1] = (n % 1000) / 100;
		y[2] = (n % 100) / 10;
		y[3] = n % 10;
		if ((y[0] != y[1]) && (y[0] != y[2]) && (y[0] != y[3]) && (y[1] != y[2])
			&& (y[1] != y[3]) && (y[2] != y[3])) {
			break;
		}
	}
	
	
	cout << n;
}*/