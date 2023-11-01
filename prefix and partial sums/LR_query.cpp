#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int mod = 1e9 + 7;
void solve()
{
    int n, q;
    cin >> n >> q;

    long long prefix[n + 1];

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (i != 1)
            prefix[i] = (prefix[i - 1] + temp);

        else
        {
            prefix[i] = temp;
        }
    }
    prefix[0] = 0;
    // for(auto x:prefix) cout<<x<<" ";

    int l, r;
    while (q--)
    {
        cin >> l >> r;
        int x = (prefix[r] - prefix[l - 1]) % mod;
        if (x < 0)
        {
            cout << (x + mod) % mod << endl;
            
        }
        else
        {
            cout << x << endl;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
  
}