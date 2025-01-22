#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        cout << i % 2;
    }

    cout << endl;
    return;
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