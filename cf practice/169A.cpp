#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int maxi = -1e9;
    for (int i = 0; i < n; i++)
    {
        int f, t;
        cin >> f >> t;
        int joy = (t > k) ? (f - (t - k)) : f;
        maxi = max(joy, maxi);
    }
    cout << maxi << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}