#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, k;
int arr[100100];

bool check(int x)
{
    int lastleft = 0;
    int needed = 0;
    for (int i = 0; i < n; i++)
    {
        if (lastleft >= arr[i])
        {
            lastleft -= arr[i];
        }
        else
        {
            needed++;
            lastleft = x - arr[i];             //at first run needed will change to 1 and last left will change to (target time - time of first wall)
                                            //we could also have initiated with lastleft = x and needed = 1
        }
        if (needed > k)
            return 0;
    }
    if (needed > k)
        return 0;
    else
        return 1;
}
void solve()
{
    cin >> n >> k;
    int lo = 0;
    int hi = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        lo = max(lo, arr[i]);
        hi += arr[i];
    }
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (hi + lo) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
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
