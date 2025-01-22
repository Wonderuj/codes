//place K points so that maximum distance bw neighbouring points is minimum

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, k;
int arr[100100];

bool check(int x)
{
    int needed = 0;
    for (int i = 1; i < n; i++)
    {
        needed += (((arr[i] - arr[i - 1]) + x - 1) / x) - 1;
    }
    return needed <= k;
}
void solve()
{
    cin >> n >> k;
    int lo = 1;              // lo = 0 if multiple points can be at the same point. (may be input can have all the points at the same point)
    int hi = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 1; i < n; i++)
    {
        hi = max(hi, arr[i] - arr[i - 1]);
    }

    int ans = -1;
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
