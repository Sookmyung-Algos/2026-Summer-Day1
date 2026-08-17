#include <iostream>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int n, a, b, c;
int ans = 0;
cin >> n;
for(int i=0; i<n; i++){
    cin >> a >> b >> c;
    if ((a + b + c) > 1)
        ans += 1;
}
cout << ans;

return 0;
}