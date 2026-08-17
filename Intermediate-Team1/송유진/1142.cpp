#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

// 직사각형의 좌표를 담을 구조체
struct Rect {
    long long x1, y1, x2, y2;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Rect> rects(n);
    vector<long long> X, Y;

    for (int i = 0; i < n; ++i) {
        double x, y, w, h;
        cin >> x >> y >> w >> h;
        
        // 소수점 첫째 자리까지 주어지므로 10을 곱하여 정수로 변환
        long long x1 = round(x * 10.0);
        long long y1 = round(y * 10.0);
        long long width = round(w * 10.0);
        long long height = round(h * 10.0);
        
        long long x2 = x1 + width;
        long long y2 = y1 + height;

        rects[i] = {x1, y1, x2, y2};
        
        X.push_back(x1);
        X.push_back(x2);
        Y.push_back(y1);
        Y.push_back(y2);
    }

    // x좌표, y좌표 각각 중복 제거 및 오름차순 정렬
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    long long total_area = 0;

    // 생성된 모든 격자를 순회
    for (size_t i = 0; i < X.size() - 1; ++i) {
        for (size_t j = 0; j < Y.size() - 1; ++j) {
            // 현재 격자의 중심점 계산
            double mid_x = (X[i] + X[i+1]) / 2.0;
            double mid_y = (Y[j] + Y[j+1]) / 2.0;

            // 중심점이 주어진 직사각형 중 하나라도 내부에 포함되는지 확인
            for (int k = 0; k < n; ++k) {
                if (rects[k].x1 <= mid_x && mid_x <= rects[k].x2 &&
                    rects[k].y1 <= mid_y && mid_y <= rects[k].y2) {
                    
                    // 포함된다면 해당 격자의 넓이를 더하고 중복 계산 방지를 위해 break
                    total_area += (X[i+1] - X[i]) * (Y[j+1] - Y[j]);
                    break; 
                }
            }
        }
    }

    // 길이에 10씩 곱했으므로 넓이는 100으로 나눔
    double ans = total_area / 100.0;

    if (ans == floor(ans)) {
        cout << (long long)ans << "\n";
    } else {
        cout << fixed << setprecision(2) << ans << "\n";
    }

    return 0;
}
