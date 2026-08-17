// Day1 - 정올 12352번 : 즐거운 회의 
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, T;
    cin >> N >> M >> T;

    vector<int> arrive(N + 1);
    vector<int> leave(N + 1);

    // 각 사람의 참석 시간 입력
    for (int i = 1; i <= N; i++) {
        cin >> arrive[i] >> leave[i];
    }

    // 차분 배열
    vector<int> diff(T + 1, 0);

    // 친한 사람들의 쌍 입력
    for (int i = 0; i < M; i++) {
        int c, d;
        cin >> c >> d;

        int start = max(arrive[c], arrive[d]);
        int end = min(leave[c], leave[d]);

        // 두 사람이 만나는 시간이 존재하는 경우
        if (start < end) {
            diff[start]++;
            diff[end]--;
        }
    }

    // 누적합을 이용해 각 시간대의 대화 중인 쌍 계산
    int current = 0;

    for (int time = 0; time < T; time++) {
        current += diff[time];
        cout << current << '\n';
    }

    return 0;
}
