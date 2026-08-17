#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> a(N);
    vector<long long> sorted(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }

    sort(sorted.begin(), sorted.end());

    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    for (int i = 0; i < N; i++) {
        int idx = lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin();

        cout << idx + 1 << ' ';
    }

    return 0;
}