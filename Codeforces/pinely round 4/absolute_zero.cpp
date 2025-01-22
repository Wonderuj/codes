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
    int op = 0;
    vector<int> ans;
    for (int i = 29; i >= 0; i--)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = abs(arr[i] - (1 << i));
        }
        ans.push_back(1 << i);
        op++;
    }

    if (arr[0] == 1)
    {
        op++;
        ans.push_back(1);
    }
    cout << op << endl;
    for (auto x : ans)
    {
        cout << x << " ";
    }
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