// Day1 - 정올 844번 : K-비둘기
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    string birds;
    cin >> birds;

    long long countR = 0;
    long long countL = 0;
    long long rlPairs = 0;

    // 첫 번째 구간 계산
    for (int i = 0; i < K; i++) {
        if (birds[i] == 'R') {
            countR++;
        } else { // L
            rlPairs += countR;
            countL++;
        }
    }

    cout << rlPairs * 2;

    // 슬라이딩 윈도우
    for (int left = 0; left + K < N; left++) {
        int right = left + K;

        // 왼쪽에서 birds[left] 제거
        if (birds[left] == 'R') {
            // 제거되는 R과 구간 내부의 모든 L 사이의 RL 쌍 제거
            rlPairs -= countL;
            countR--;
        } else { // L
            countL--;
        }

        // 오른쪽에서 birds[right] 추가
        if (birds[right] == 'R') {
            // 새 R은 RL 쌍의 왼쪽 원소가 아니므로 쌍을 만들지 않음
            countR++;
        } else { // L
            // 새 L의 왼쪽에 있는 모든 R과 RL 쌍 생성
            rlPairs += countR;
            countL++;
        }

        cout << ' ' << rlPairs * 2;
    }

    cout << '\n';

    return 0;
}
