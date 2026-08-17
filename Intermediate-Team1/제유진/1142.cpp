#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rectangle {
    int x1;
    int y1;
    int x2;
    int y2;
};

int toInteger(const string& value) {
    size_t dot = value.find('.');

    if (dot == string::npos) {
        return stoi(value) * 10;
    }

    int integerPart = stoi(value.substr(0, dot));
    int decimalPart = 0;

    if (dot + 1 < value.size()) {
        decimalPart = value[dot + 1] - '0';
    }

    return integerPart * 10 + decimalPart;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Rectangle> rectangles;
    vector<int> xCoordinates;

    for (int i = 0; i < N; i++) {
        string xInput, yInput, widthInput, heightInput;
        cin >> xInput >> yInput >> widthInput >> heightInput;

        int x = toInteger(xInput);
        int y = toInteger(yInput);
        int width = toInteger(widthInput);
        int height = toInteger(heightInput);

        rectangles.push_back({
            x,
            y,
            x + width,
            y + height
        });

        xCoordinates.push_back(x);
        xCoordinates.push_back(x + width);
    }

    // x좌표 정렬 및 중복 제거
    sort(xCoordinates.begin(), xCoordinates.end());

    xCoordinates.erase(
        unique(xCoordinates.begin(), xCoordinates.end()),
        xCoordinates.end()
    );

    long long totalArea = 0;

    // 인접한 x좌표 사이를 하나씩 스위핑
    for (int i = 0; i + 1 < xCoordinates.size(); i++) {
        int currentX = xCoordinates[i];
        int nextX = xCoordinates[i + 1];
        int width = nextX - currentX;

        vector<pair<int, int>> yIntervals;

        // 현재 x구간을 덮는 직사각형의 y구간 수집
        for (const Rectangle& rectangle : rectangles) {
            if (rectangle.x1 <= currentX &&
                nextX <= rectangle.x2) {

                yIntervals.push_back({
                    rectangle.y1,
                    rectangle.y2
                });
            }
        }

        if (yIntervals.empty()) {
            continue;
        }

        // 백준 2170번과 동일하게 y구간 병합
        sort(yIntervals.begin(), yIntervals.end());

        int currentStart = yIntervals[0].first;
        int currentEnd = yIntervals[0].second;

        long long coveredY = 0;

        for (int j = 1; j < yIntervals.size(); j++) {
            int nextStart = yIntervals[j].first;
            int nextEnd = yIntervals[j].second;

            if (nextStart <= currentEnd) {
                currentEnd = max(currentEnd, nextEnd);
            } else {
                coveredY += currentEnd - currentStart;

                currentStart = nextStart;
                currentEnd = nextEnd;
            }
        }

        // 마지막 y구간 추가
        coveredY += currentEnd - currentStart;

        totalArea += static_cast<long long>(width) * coveredY;
    }

    // 좌표를 10배 했으므로 넓이는 100배 된 상태
    if (totalArea % 100 == 0) {
        cout << totalArea / 100;
    } else {
        cout << totalArea / 100 << '.'
             << setw(2) << setfill('0') << totalArea % 100;
    }

    return 0;
}
