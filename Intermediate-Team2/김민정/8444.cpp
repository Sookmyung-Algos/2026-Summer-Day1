#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    long long r = 0;
    long long l = 0;
    long long cnt = 0;

    for(int i=0; i<k; i++) {
        if(s[i] == 'R') {
            r++;
        }
        else {
            cnt += r;
            l++;
        }
    }

    cout << cnt * 2;

    for(int i=k; i<n; i++) {
        if(s[i-k] == 'R') {
            r--;
            cnt -= l;
        }
        else {
            l--;
        }

        if(s[i] == 'R') {
            r++;
        }
        else {
            cnt += r;
            l++;
        }

        cout << " " << cnt * 2;
    }

    return 0;
}
