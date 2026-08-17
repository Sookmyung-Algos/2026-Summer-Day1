#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int N;

// 스위핑할 좌표(위치)들, 각 위치에서 지나간 소 번호
int coord[100001];
int cowId[100001];

// 좌표압축 결과
int compressedCoord[100001];
int coordCnt;

// 소의 시작 위치 기록, 이미 열렸는지 여부
int startPos[50001];
bool opened[50001];

// 펜윅 트리
long long fenw[100001];

// 펜윅 트리에 값 추가
void update(int i, long long val){
    for(; i<=coordCnt; i+=i&(-i)){
        fenw[i] += val;
    }
}

// 펜윅 트리 누적합 쿼리 (1~i)
long long query(int i){
    long long s = 0;
    for(; i>0; i-=i&(-i)){
        s += fenw[i];
    }
    return s;
}

// 구간 [l, r] 합 쿼리
long long queryRange(int l, int r){
    if(l > r) return 0;
    return query(r) - query(l-1);
}

// 값 정렬 및 좌표압축
void compress(){
    for(int i=1; i<=2*N; i++){
        compressedCoord[i] = coord[i];
    }
    sort(compressedCoord+1, compressedCoord+2*N+1);
    coordCnt = unique(compressedCoord+1, compressedCoord+2*N+1) - (compressedCoord+1);
}

// 좌표압축된 위치를 스위핑하며 열림/닫힘 이벤트 처리
long long sweep(){
    long long answer = 0;

    for(int i=1; i<=2*N; i++){
        int cow = cowId[i];
        int pos = lower_bound(compressedCoord+1, compressedCoord+coordCnt+1, coord[i]) - compressedCoord;

        if(!opened[cow]){
            // 구간 열림 이벤트: 시작 위치에 +1
            opened[cow] = true;
            startPos[cow] = pos;
            update(pos, 1);
        } else {
            // 구간 닫힘 이벤트
            int L = startPos[cow];
            int R = pos;

            // (L, R) 사이에서 아직 살아있는(닫히지 않은) 현의 개수 = 교차 쌍 수
            answer += queryRange(L+1, R-1);

            // 자기 자신이 시작 위치(L)에 찍어뒀던 +1을 지움 (R이 아님에 주의!)
            update(L, -1);
        }
    }

    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i=1; i<=2*N; i++){
        cin >> cowId[i];
        coord[i] = i;
    }

    compress();
    long long answer = sweep();

    cout << answer << "\n";

    return 0;
}