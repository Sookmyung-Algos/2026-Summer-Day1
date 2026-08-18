#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int problemNum;
	int result = 0;

	cin >> problemNum;
	int petya;
	int vasya;
	int tonya;

	for (int i = 0; i < problemNum; i++) {
		cin >> petya >> vasya >> tonya;

		if (petya + vasya + tonya >= 2) {
			result++;
		}
	}

	cout << result;

	return 0;
}