#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int y;
	cin >> y;

	while (1) {
		y++;

		int thousand = y / 1000;
		int hundred = y / 100 % 10;
		int ten = y / 10 % 10;
		int one = y % 10;
		
		set<int> s = { thousand, hundred, ten, one };
		if (s.size() == 4) {
			cout << y;
			break;
		}
	}

	return 0;
}