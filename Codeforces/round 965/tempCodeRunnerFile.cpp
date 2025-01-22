#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    vector<pair<int, int>> v;

    if (k >= 2)
    {
        for (int i = 1; i <= k; i++)
        {
            v.push_back({x, y + i});
            v.push_back({x, y - i});
        }
    }
    if (k % 2)
    {
        v.push_back({x, y});
    }
    for (auto &[a, b] : v)
    {
        cout << a << " " << b << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    while (_t--)
        solve();
}