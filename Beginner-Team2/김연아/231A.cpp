#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // 문제 개수 입력

    int count = 0; // 푼 문제 개수

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c; // 각 문제에 대한 확신 여부 입력

        if (a + b + c >= 2) { // 최소 두 명이 확신하면 푼다
            count++;
        }
    }

    cout << count << endl; // 결과 출력
    return 0;
}
