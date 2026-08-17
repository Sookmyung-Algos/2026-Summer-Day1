#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int size;

public:
    FenwickTree(int size) : size(size) {
        tree.assign(size + 1, 0);
    }

    // index 위치에 value를 더함
    void add(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    // 1번부터 index번까지의 합을 구함
    int sum(int index) {
        int result = 0;

        while (index > 0) {
            result += tree[index];
            index -= index & -index;
        }

        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> height(N);
    vector<int> compressed;

    for (int i = 0; i < N; i++) {
        cin >> height[i];
        compressed.push_back(height[i]);
    }

    // 좌표 압축을 위해 키를 정렬
    sort(compressed.begin(), compressed.end());

    vector<int> leftTaller(N);
    vector<int> rightTaller(N);

    FenwickTree leftTree(N);

    // 왼쪽에 있는 더 큰 병아리의 수
    for (int i = 0; i < N; i++) {
        int rank =
            lower_bound(
                compressed.begin(),
                compressed.end(),
                height[i]
            ) - compressed.begin() + 1;

        int lessOrEqual = leftTree.sum(rank);

        leftTaller[i] = i - lessOrEqual;

        leftTree.add(rank, 1);
    }

    FenwickTree rightTree(N);

    // 오른쪽에 있는 더 큰 병아리의 수
    for (int i = N - 1; i >= 0; i--) {
        int rank =
            lower_bound(
                compressed.begin(),
                compressed.end(),
                height[i]
            ) - compressed.begin() + 1;

        int rightCount = N - 1 - i;
        int lessOrEqual = rightTree.sum(rank);

        rightTaller[i] = rightCount - lessOrEqual;

        rightTree.add(rank, 1);
    }

    int answer = 0;

    for (int i = 0; i < N; i++) {
        int smaller = min(leftTaller[i], rightTaller[i]);
        int larger = max(leftTaller[i], rightTaller[i]);

        if (larger > 2 * smaller) {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}
