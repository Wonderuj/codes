#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bool evens = false, odds = false;
    for (auto x : arr)
    {
        if (x % 2 == 0)
        {
            evens = true;
        }
        else
            odds = true;
    }

    if (evens == true and odds == true)
    {
        cout << "-1\n";
        return;
    }

    for (int i = 29; i >= 0; i--)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = abs(arr[i] - (1 << i));
        }
        cout << (1 << i) << " ";
    }

    if (arr[0] == 1)
        cout << 1 << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}