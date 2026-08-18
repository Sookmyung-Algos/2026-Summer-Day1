#include <bits/stdc++.h>
using namespace std;

struct Square
{
    int x;
    int y1, y2;
    int chk;
};
bool cmp(Square a, Square b)
{
    if (a.x == b.x)
        return a.chk < b.chk;
    return a.x < b.x;
}
vector<Square> v;

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        double x, y, w, h;
        cin >> x >> y >> w >> h;

        int x1 = (int)round(x * 10);
        int x2 = (int)round((x + w) * 10);
        int y1 = (int)round(y * 10);
        int y2 = (int)round((y + h) * 10);

        v.push_back({x1, y1, y2, -1});
        v.push_back({x2, y1, y2, 1});
    }
    sort(v.begin(), v.end(), cmp);
    int A[20005] = {
        0,
    };
    long long lx = v[0].x;
    long long ans = 0;
    for (Square s : v)
    {
        int cnt = 0;
        for (int i = 0; i < 20005; i++)
        {
            if (A[i] > 0)
                cnt++;
        }
        ans += (long long)cnt * (s.x - lx);
        for (int i = s.y1; i < s.y2; i++)
        {
            if (s.chk == -1)
                A[i]++;
            else
                A[i]--;
        }
        lx = s.x;
    }
    if (ans % 100 == 0)
    {
        cout << ans/100;
        return 0;
    }
    cout << fixed;
    cout.precision(2);
    cout << (double)ans / 100.0;
    return 0;
}
