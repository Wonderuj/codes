#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x, y;
    cin >> x >> y;
    long long ans = 0;
    while (y > x)
    {
        if (y % 2 == 0)
        {
            y = y / 2;
            ans++;
        }
        else
        {
            y++;
            ans++;
        }
    }

    ans += x - y;
    cout << ans << '\n';
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