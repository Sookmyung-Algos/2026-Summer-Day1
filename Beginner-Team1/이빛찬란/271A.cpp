#include <iostream>
#include <set>
using namespace std;

bool hasDistinctDigits(int year) {
    set<int> digits;
    while (year > 0) {
        int d = year % 10;
        if (digits.count(d)) return false;
        digits.insert(d);
        year /= 10;
    }
    return true;
}

int main() {
    int y;
    cin >> y;
    int cur = y + 1;
    while (!hasDistinctDigits(cur)) {
        cur++;
    }
    cout << cur << endl;
    return 0;
}
