#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    int arr[n + 1][m + 1];
    int prefix[n + 2][m + 2];

    memset(prefix, 0, sizeof(prefix));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    // cout<<"ipt taken\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i <= m; j++)
        {
            prefix[i][j] = arr[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
    // cout << "prefix build\n";

    while (q--)
    {
        int l, r, u, d;
        cin >> l >> u >> d >> r;
        // cout << "taking lrud \n";
        int ans = (prefix[d][r] - prefix[d][l - 1] - prefix[u - 1][r] + prefix[u - 1][l - 1]) % mod;
        if (ans < 0)
            ans += mod;
        cout << ans << '\n';
    }
    // cout<<"here";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}