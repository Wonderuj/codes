#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
void solve()
{
    int n, q;
    cin >> n >> q;
    int arr[n + 1], brr[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        brr[i] = (arr[i] * i) % mod;
    }

    arr[0] = 0;
    brr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
        arr[i] %= mod;
        brr[i] += brr[i - 1];
        brr[i] %= mod;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int x = (arr[r] - arr[l - 1]);
        int y = (brr[r] - brr[l - 1]);
        int ans = y + ((1 - l) * x);

        ans = (ans % mod + mod) % mod;
        cout << ans << endl;
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

