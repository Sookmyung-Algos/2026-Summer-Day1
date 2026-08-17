#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, T;
    cin >> n >> m >> T;

    vector<vector<int>> in(T + 1);
    vector<vector<int>> out(T + 1);

    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;

        in[a].push_back(i);
        out[b].push_back(i);
    }

    vector<vector<int>> f(n + 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        f[a].push_back(b);
        f[b].push_back(a);
    }

    vector<bool> check(n + 1, false);

    long long cnt = 0;

    for(int t = 0; t < T; t++) {

        for(int x : out[t]) {
            for(int y : f[x]) {
                if(check[y]) cnt--;
            }

            check[x] = false;
        }

        for(int x : in[t]) {
            for(int y : f[x]) {
                if(check[y]) cnt++;
            }

            check[x] = true;
        }

        cout << cnt << '\n';
    }

    return 0;
}
