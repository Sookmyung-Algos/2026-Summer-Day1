#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int size;

public:
    FenwickTree(int size) {
        this->size = size;
        tree.resize(size + 1, 0);
    }

    // index 위치에 value를 더함
    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    // 1번 위치부터 index 위치까지의 합
    int query(int index) {
        int sum = 0;

        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }

        return sum;
    }

    // left부터 right까지의 합
    int rangeQuery(int left, int right) {
        if (left > right) {
            return 0;
        }

        return query(right) - query(left - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    FenwickTree fenwick(2 * N);

    // firstPosition[cow]
    // 해당 소가 처음 등장한 위치
    vector<int> firstPosition(N + 1, 0);

    long long answer = 0;

    for (int position = 1; position <= 2 * N; position++) {
        int cow;
        cin >> cow;

        if (firstPosition[cow] == 0) {
            // 처음 등장한 소
            firstPosition[cow] = position;
            fenwick.update(position, 1);
        } else {
            // 두 번째로 등장한 소
            int start = firstPosition[cow];

            // start와 position 사이에서 아직 열려 있는 소의 개수
            answer += fenwick.rangeQuery(start + 1, position - 1);

            // 현재 소는 끝났으므로 시작 위치 제거
            fenwick.update(start, -1);
        }
    }

    cout << answer << '\n';

    return 0;
}
