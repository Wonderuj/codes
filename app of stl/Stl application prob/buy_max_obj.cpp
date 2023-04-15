#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];  
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (i)
            arr[i] += arr[i - 1];
    }
    auto it = upper_bound(arr, arr + n, m);
    cout << it - arr << endl;
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