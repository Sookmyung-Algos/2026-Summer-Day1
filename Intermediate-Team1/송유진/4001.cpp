#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FenwickTree {
    int size;
    vector<int> tree;

    FenwickTree(int n) : size(n) {
        tree.assign(n + 1, 0);
    }

    // 값 업데이트
    void update(int i, int delta) {
        while (i <= size) {
            tree[i] += delta;
            i += i & -i;
        }
    }

    // 1부터 i까지의 누적합 쿼리
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }

    // left부터 right까지의 구간합 쿼리
    int query(int left, int right) {
        if (left > right) return 0;
        return query(right) - query(left - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> h(n);
    vector<long long> sorted_h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        sorted_h[i] = h[i];
    }

    // 좌표 압축을 위한 정렬
    sort(sorted_h.begin(), sorted_h.end());

    // 이진 탐색을 통해 원래 값들을 1 ~ N의 순위로 변경
    vector<int> compressed_h(n);
    for (int i = 0; i < n; ++i) {
        compressed_h[i] = lower_bound(sorted_h.begin(), sorted_h.end(), h[i]) - sorted_h.begin() + 1;
    }

    vector<int> L(n, 0);
    vector<int> R(n, 0);

    FenwickTree fwLeft(n);
    for (int i = 0; i < n; ++i) {
        // 나보다 큰 병아리의 수 카운트
        L[i] = fwLeft.query(compressed_h[i] + 1, n);
        // 내 키를 트리에 등록
        fwLeft.update(compressed_h[i], 1);
    }

    // 오른쪽에서부터 역순으로 순회하며 R[i] 계산
    FenwickTree fwRight(n);
    for (int i = n - 1; i >= 0; --i) {
        R[i] = fwRight.query(compressed_h[i] + 1, n);
        fwRight.update(compressed_h[i], 1);
    }

    // 조건에 맞는 불균형 병아리 수 계산
    int unbalanced_count = 0;
    for (int i = 0; i < n; ++i) {
        if (L[i] > 2 * R[i] || R[i] > 2 * L[i]) {
            unbalanced_count++;
        }
    }

    cout << unbalanced_count << "\n";

    return 0;
}
