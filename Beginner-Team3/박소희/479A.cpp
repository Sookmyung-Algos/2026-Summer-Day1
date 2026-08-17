#include <iostream>
#include <algorithm>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int a, b, c, m;
cin >> a >> b >> c;
m = max({a+b+c, a*b*c, a*b+c, a+b*c, a*(b+c), (a+b)*c});

cout << m;
return 0;
}