// #include <bits/stdc++.h>
// using namespace std;
// //#define int long long
// #define endl '\n'

// string s1, s2;
// int n, m;
// int dp[1010][1010];
// int rec(int l1, int l2)
// {
//     if (l1 == n || l2 == m)
//     {
//         return 0;
//     }

//     if (dp[l1][l2] != -1)
//     {
//         return dp[l1][l2];
//     }
//     int ans = 0;
//     if (s1[l1] == s2[l2])
//     {
//         ans = max(ans,1 + rec(l1 + 1, l2 + 1));
//     }
//     // else
//     // {
//     //     ans = max(rec(l1 + 1, l2), rec(l1, l2 + 1));
//     // }
//     rec(l1 + 1, l2);
//     rec(l1, l2 + 1);

//     return dp[l1][l2] = ans;
// }
// void solve()
// {
//     cin >> s1 >> s2;
//     n = s1.length();
//     m = s2.length();
//     memset(dp, -1, sizeof(dp));
//     cout << rec(0, 0) << endl;
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

// this code is wrong becacue we are asked for longest substring not subsequence

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int dp[1010][1010];
string s1, s2;
int n, m;
int rec(int l1, int l2)
{
    if (l1 == n || l2 == m)
    {
        return 0;
    }

    if (dp[l1][l2] != -1)
    {
        return dp[l1][l2];
    }

    int ans = 0;
    if (s1[l1] == s2[l2])
    {
        ans = 1 + rec(l1 + 1, l2 + 1);
    }
    else
    {
        ans = 0;
        rec(l1 + 1, l2);
        rec(l1, l2 + 1);
    }
    return dp[l1][l2] = ans;
}
void solve()
{
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    memset(dp, -1, sizeof(dp));
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            x = max(x, rec(i, j));
        }
    }
    cout << x << endl;
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