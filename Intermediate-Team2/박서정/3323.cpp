// ÁÂÇ¥ ¾ĞÃà 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> a(N);
    vector<long long> compressed;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        compressed.push_back(a[i]);
    }

    sort(compressed.begin(), compressed.end());


    compressed.erase(
        unique(compressed.begin(), compressed.end()),
        compressed.end()
    );

    for (int i = 0; i < N; i++) {
        int idx = lower_bound(
            compressed.begin(),
            compressed.end(),
            a[i]
        ) - compressed.begin();

        cout << idx + 1 << ' ';
    }

    return 0;
}