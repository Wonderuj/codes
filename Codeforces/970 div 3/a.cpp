#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    // if (a % 2 == 0)
    // {
    //     if ((b % 2 == 1 and a > 1) or b % 2 == 0)
    //     {
    //         cout << "YES\n";
    //         return;
    //     }
    //     else cout<<"NO\n";
    //     return;
    // }

    // cout<<"NO\n";
    if (a % 2)
    {
        cout << "NO\n";
        return;
    }
    if (a == 0 and b % 2)
    {
        cout << "NO\n";
        return;
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