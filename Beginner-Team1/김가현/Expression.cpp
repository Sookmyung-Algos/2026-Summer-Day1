// 479A Expression

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    
    int ans1 = a+b+c;
    int ans2 = (a+b)*c;
    int ans3 = a+b*c;
    int ans4 = a*b+c;
    int ans5 = a*(b+c);
    int ans6 = a*b*c;

    int result = max({ans1, ans2, ans3, ans4, ans5, ans6});

    cout << result;
}