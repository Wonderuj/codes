#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }
    int ans = 0, cur = 0;
    for (int i = 1; i < n; i++)
    {
        int ele = v[i];
        while (ele >= 2 * v[i - 1] and cur > 0)
        {
            cur--;
            ele /= 2;
        }
        while (ele < v[i - 1])
        {
            cur++;
            ele *= 2;
        }
        ans += cur;
    }
    cout << ans << endl;
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