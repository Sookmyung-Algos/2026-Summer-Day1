#include <iostream>
#include <string>
#include <set>
using namespace std;

bool isDistinct(int year) {
    string s = to_string(year);
    set<char> digits(s.begin(), s.end());
    return digits.size() == s.size();
}

int main() {
    int y;
    cin >> y;

    int ans = y + 1;
    while (!isDistinct(ans)) {
        ans++;
    }

    cout << ans << endl;
    return 0;
}
