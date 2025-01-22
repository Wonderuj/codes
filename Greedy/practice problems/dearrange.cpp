// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;
//     map<int, int> mp;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         mp[x]++;
//     }
//     int maxi = 0;
//     for (auto v : mp)
//     {
//         maxi = max(maxi, v.second);
//     }
//     int ans;
//     ans = n - max((2 * maxi - n), 0);
//     cout << ans << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int _t;
//     cin >> _t;
//     while (_t--)
//         solve();
// }

#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>vp;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    int maxi = 0;
    for (auto v : mp)
    {
        maxi = max(maxi, v.second);
    }
    int ans;
    ans = n - max((2 * maxi - n), 0);
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