// K-ºñµÑ±â

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

    long long pairCount = 0;
    long long cntR = 0;
    long long cntL = 0;

    for (int i = 0; i < K; i++) {
        if (s[i] == 'R') {
            cntR++;
        }
        else {
            pairCount += cntR;
            cntL++;
        }
    }

    cout << pairCount * 2;

    for (int left = 0; left + K < N; left++) {
        if (s[left] == 'R') {
            cntR--;
            pairCount -= cntL;
        }
        else {
            cntL--;
        }

        int right = left + K;

        if (s[right] == 'R') {
            cntR++;
        }
        else {
            pairCount += cntR;
            cntL++;
        }

        cout << ' ' << pairCount * 2;
    }

    cout << '\n';

    return 0;
}