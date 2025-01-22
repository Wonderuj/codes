#include <bits/stdc++.h>
using namespace std;
int n;
// int a[10010];
// int b[10010];
// int c[10010];  so insted of this and making a pair, just simply use 2d array
int reward[100100][3];
int dp[100100][3];
int rec(int level, int prev)
{
    if (level == n)
    {
        return 0;
    }

    if (dp[level][prev] != -1)
    {
        return dp[level][prev];
    }

    int ans = 0;
    for (int j = 0; j < 3; j++)
    {
        if (j != prev)
        {
            ans = max(ans, rec(level + 1, j) + reward[level][j]);
        }
    }
    return dp[level][prev] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> reward[i][j];
            dp[i][j] = -1;
        }
    }

    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        ans = max(ans, rec(0, i));
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}