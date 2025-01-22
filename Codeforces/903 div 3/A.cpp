#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string t, s;
    cin >> s >> t;
    int ans = 0;
    if (s.find(t) != string::npos)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        s += s;
        ans++;
        if (s.find(t) != string::npos)
        {
            cout << ans << endl;
            return;
        }
    }
    cout << -1 << endl;
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