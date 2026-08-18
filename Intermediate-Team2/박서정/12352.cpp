// Áñ°Å¿î È¸ÀÇ

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, T;
    cin >> N >> M >> T;

    vector<int> a(N + 1), b(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> a[i] >> b[i];
    }

    vector<long long> diff(T + 1, 0);

    for (int i = 0; i < M; i++) {
        int c, d;
        cin >> c >> d;

        int l = max(a[c], a[d]);
        int r = min(b[c], b[d]);

        if (l < r) {
            diff[l]++;
            diff[r]--;
        }
    }

    long long cur = 0;

    for (int t = 0; t < T; t++) {
        cur += diff[t];
        cout << cur << '\n';
    }

    return 0;
}