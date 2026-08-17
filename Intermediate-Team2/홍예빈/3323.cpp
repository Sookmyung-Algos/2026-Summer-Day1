// Day1 - 정올 3323번 : 좌표 압축1
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> coordinates(N);

    for (int i = 0; i < N; i++) {
        cin >> coordinates[i];
    }

    // 원본 배열 복사 후 정렬
    vector<long long> sortedCoordinates = coordinates;
    sort(sortedCoordinates.begin(), sortedCoordinates.end());

    // 중복 제거
    sortedCoordinates.erase(
        unique(sortedCoordinates.begin(), sortedCoordinates.end()),
        sortedCoordinates.end()
    );

    // 각 원소의 압축된 좌표 출력
    for (int i = 0; i < N; i++) {
        int compressedIndex =
            lower_bound(
                sortedCoordinates.begin(),
                sortedCoordinates.end(),
                coordinates[i]
            ) - sortedCoordinates.begin();

        cout << compressedIndex + 1;

        if (i < N - 1) {
            cout << ' ';
        }
    }

    cout << '\n';

    return 0;
}
