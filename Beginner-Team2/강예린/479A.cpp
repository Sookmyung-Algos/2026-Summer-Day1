#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

    int result = max({
        a + b + c,
        a * b * c,
        a + b * c,
        a * b + c,
        a * (b + c),
        (a + b) * c
        });

    cout << result;

    return 0;
}