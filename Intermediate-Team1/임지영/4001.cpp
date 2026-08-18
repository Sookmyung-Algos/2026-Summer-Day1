#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int N;

// 병아리 키, 좌표압축된 순위, 좌/우 더 큰 병아리 수, 펜윅 트리
long long h[100001];
long long sortedH[100001];
int rankArr[100001], L[100001], R[100001];
int fenw[100001];

// 펜윅 트리에 값 추가
void update(int i){
    for(; i<=N; i+=i&(-i)){
        fenw[i]++;
    }
}

// 펜윅 트리 누적합 쿼리
int query(int i){
    int s = 0;
    for(; i>0; i-=i&(-i)){
        s += fenw[i];
    }
    return s;
}

// 값 정렬 및 좌표 압축: 키가 모두 다르므로 순위를 1~N으로 매핑
void compress(){
    for(int i=1; i<=N; i++){
        sortedH[i] = h[i];
    }

    // 값 정렬
    sort(sortedH+1, sortedH+N+1);

    // 정렬된 배열에서 이분 탐색으로 각 값의 순위(좌표) 찾기
    for(int i=1; i<=N; i++){
        int pos = lower_bound(sortedH+1, sortedH+N+1, h[i]) - sortedH;
        rankArr[i] = pos;
    }
}

// 왼쪽에서 오른쪽으로 훑으며 L 배열(자신보다 왼쪽에 있는 더 큰 병아리 수) 계산
void calcLeft(){
    memset(fenw, 0, sizeof(fenw));

    for(int i=1; i<=N; i++){
        int seen = query(N);
        int leq = query(rankArr[i]);
        L[i] = seen - leq;
        update(rankArr[i]);
    }
}

// 오른쪽에서 왼쪽으로 훑으며 R 배열(자신보다 오른쪽에 있는 더 큰 병아리 수) 계산
void calcRight(){
    memset(fenw, 0, sizeof(fenw));

    for(int i=N; i>=1; i--){
        int seen = query(N);
        int leq = query(rankArr[i]);
        R[i] = seen - leq;
        update(rankArr[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> h[i];
    }

    compress();
    calcLeft();
    calcRight();

    int answer = 0;

    for(int i=1; i<=N; i++){
        int M = max(L[i], R[i]);
        int m = min(L[i], R[i]);

        if(M > 2*m){
            answer++;
        }
    }

    cout << answer << "\n";

    return 0;
}