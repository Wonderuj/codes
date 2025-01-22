#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q, n;
    cin >> q >> n;
    if (q == 1)
    {
        for (int i = 0; i * i <= n; i++)
        {
            if (i * i == n)
            {
                cout << "YES" << '\n';
                return;
            }
        }
    }
    else
    {
        for (int i = 0; i * i * i <= n; i++)
        {
            if (i * i * i == n)
            {
                cout << "YES" << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    // string d;
    // getline(cin,d);
    while (_t--)
        solve();
}