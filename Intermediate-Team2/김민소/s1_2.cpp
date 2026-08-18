#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    long long rCnt = 0;
    long long lCnt = 0;
    long long pairs = 0;

    for (int i = 0; i < K; i++) {
        if (s[i] == 'R') {
            rCnt++;
        }
        else {
            pairs += rCnt;
            lCnt++;
        }
    }

    cout << pairs * 2;

    for (int left = 0; left + K < N; left++) {
        int right = left + K;

        if (s[left] == 'R') {
            pairs -= lCnt;
            rCnt--;
        }
        else {
            lCnt--;
        }

        if (s[right] == 'R') {
            rCnt++;
        }
        else {
            pairs += rCnt;
            lCnt++;
        }

        cout << ' ' << pairs * 2;
    }

    cout << '\n';

    return 0;
}