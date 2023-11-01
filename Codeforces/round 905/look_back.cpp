#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt(int &x, int &y)
{
    int ans = 0;
    while (x < y)
    {
        x *= 2;
        ans++;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            ans += cnt(arr[i], arr[i - 1]);
        }
    }
    cout<<ans<<'\n';
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