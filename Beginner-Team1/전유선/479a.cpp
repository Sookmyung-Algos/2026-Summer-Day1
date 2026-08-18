#include <iostream>
using namespace std;

int main() {
	int n[3];
	int rst[6] = { 0, };
	int max = 0;

	for (int i = 0; i < 3; i++) {
		cin >> n[i];
	}
	
	rst[0] = n[0] * n[1] * n[2];
	rst[1] = n[0] * (n[1] + n[2]);
	rst[2] = (n[1] + n[0]) * n[2];
	rst[3] = n[0] + n[1] + n[2];
	rst[4] = n[0] + (n[1] * n[2]);
	rst[5] = (n[1] * n[0]) + n[2];

	
	for (int i = 0; i < 6; i++) {
		if (rst[i] > max) {
			max = rst[i];
		}
	}

	cout << max;
}