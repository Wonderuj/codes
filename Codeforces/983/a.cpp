#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int arr[2] = {0};
    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        arr[x]++;
    }
    int maxi = min(arr[0], arr[1]);
    cout << (arr[0] % 2) << " " << maxi << endl;
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