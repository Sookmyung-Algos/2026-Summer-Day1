#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int x1 = a + b + c;
    int x2 = a * b * c;
    int x3 = (a + b) * c;
    int x4 = a * (b + c);
    int x5 = a + b * c;
    int x6 = a * b + c;

    cout << max({ x1, x2, x3, x4, x5, x6 });

    return 0;
}