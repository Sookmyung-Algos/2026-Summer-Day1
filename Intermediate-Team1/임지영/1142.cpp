#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>
#include <iomanip>

using namespace std;

int N;

// 직사각형의 좌표 (10배 스케일한 정수값)
long long rx1[31], ry1[31], rx2[31], ry2[31];

// 좌표압축용 배열
long long xs[61], ys[61];
int xCnt, yCnt;

// 입력 처리: 실수를 10배해서 정수로 변환 (소수점 오차 방지)
void input(){
    for(int i=0; i<N; i++){
        double x, y, w, h;
        cin >> x >> y >> w >> h;

        long long X = (long long)round(x*10);
        long long Y = (long long)round(y*10);
        long long W = (long long)round(w*10);
        long long H = (long long)round(h*10);

        rx1[i] = X;
        ry1[i] = Y;
        rx2[i] = X + W;
        ry2[i] = Y + H;

        xs[2*i] = rx1[i];
        xs[2*i+1] = rx2[i];
        ys[2*i] = ry1[i];
        ys[2*i+1] = ry2[i];
    }
}

// 값 정렬 및 좌표압축: 중복 제거
void compress(){
    sort(xs, xs+2*N);
    sort(ys, ys+2*N);

    xCnt = unique(xs, xs+2*N) - xs;
    yCnt = unique(ys, ys+2*N) - ys;
}

// 격자 브루트포스로 전체 넓이 계산 (100배 스케일된 정수 넓이 반환)
long long solve(){
    long long totalArea = 0;

    for(int i=0; i<xCnt-1; i++){
        for(int j=0; j<yCnt-1; j++){
            bool covered = false;

            // 이 칸을 완전히 덮는 직사각형이 있는지 확인
            for(int k=0; k<N; k++){
                if(rx1[k] <= xs[i] && rx2[k] >= xs[i+1] && ry1[k] <= ys[j] && ry2[k] >= ys[j+1]){
                    covered = true;
                    break;
                }
            }

            if(covered){
                totalArea += (xs[i+1]-xs[i]) * (ys[j+1]-ys[j]);
            }
        }
    }

    return totalArea;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    input();
    compress();

    long long totalArea = solve(); // 100배 스케일된 정수 넓이

    // 소수점 이하가 0이면 정수로, 아니면 소수점 둘째자리까지 출력
    if(totalArea % 100 == 0){
        cout << totalArea/100 << "\n";
    } else {
        cout << fixed << setprecision(2) << (double)totalArea/100.0 << "\n";
    }

    return 0;
}