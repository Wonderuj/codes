/*You are given the arrival and leaving time of N customers. Find the maximum number of customers at any time. 
All arriving and leaving times are distinct.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array.

Each of the next N lines contain two space-separated integers A, B - the arrival and leaving time of the customer.*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vp;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vp.push_back({a, +1});
        vp.push_back({b, -1});
    }
    sort(vp.begin(), vp.end());
    int ans = 0;
    int cur = 0;
    for (auto v : vp)
    {
        if (v.second)
        {
            cur += v.second;
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';
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