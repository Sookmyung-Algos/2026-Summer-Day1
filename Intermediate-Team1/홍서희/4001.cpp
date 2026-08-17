#include <bits/stdc++.h>
using namespace std;

struct State
{
    int height, index;
};
bool cmp(State a, State b)
{
    return a.height > b.height;
}
struct BIT
{
    vector<int> tree;
    int size;
    BIT(int n)
    {
        size = n;
        tree.assign(n + 5, 0);
    }
    void update(int index, int val)
    {
        index++;
        while (index < tree.size())
        {
            tree[index] += val;
            index += index & -index;
        }
    }
    int query(int index)
    {
        int ret = 0;
        index++;
        while (index > 0)
        {
            ret += tree[index];
            index -= index & -index;
        }
        return ret;
    }
};

int main()
{

    int n;
    cin >> n;
    vector<State> h(n);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i].height;
        h[i].index = i;
    }
    sort(h.begin(), h.end(), cmp);
    BIT bit(n);
    int ret = 0;
    int seen = 0;
    for (auto cur : h)
    {
        int l = bit.query(cur.index);
        int r = seen - l;
        if (max(l, r) > 2 * min(l, r))
            ret++;
        bit.update(cur.index, 1);
        seen++;
    }
    cout << ret;

    return 0;
}
