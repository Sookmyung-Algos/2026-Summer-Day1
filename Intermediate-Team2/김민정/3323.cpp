#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for(int i=0; i<n; i++) {
        int num = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        cout << num;

        if(i != n-1) cout << " ";
    }

    return 0;
}
