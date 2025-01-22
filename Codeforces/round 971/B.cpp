#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }
    vector<bool> filled(n + 1, false);
    filled[v[0]] = true;

    for (int i = 1; i < n; i++)
    {
        int x = v[i];
        if ((x > 1 and filled[x - 1]) or (filled[x + 1]))
        {
            filled[x] = true;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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