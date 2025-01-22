// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// int n,k;
// int arr[100100];
// int dp[100100];

// int rec(int level)
// { // min score to reach from 1 to level
//     // base case and prunung
//     if (level <= 0)
//     {
//         return 0;
//     }

//     // cache check
//     if (dp[level] != -1)
//     {
//         return dp[level];
//     }

//     // compute
//     int cost=0;
//     int ans=INT_MAX;
//     if (level > k-1)
//     {
//         for(int i=1;i<=k;i++)
//         cost = (rec(level - i) + abs(arr[level] - arr[level - i]));
//         ans=min(cost,ans);
//     }
//     if (level < k)
//     {
//         for(int i=0;i<=k;i++)
//         {
//         cost = abs(arr[0] - arr[i]);
//         }
//     }

//     return dp[level] = ans;
// }

// void solve()
// {
//     cin >> n>>k;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     memset(dp, -1, sizeof(dp));
//     cout << rec(n - 1) << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define first f
#define second s

int n, k;
vector<int> v;
int dp[100009];

int rec(int level)
{
    if (level == 0)
        return 0;
    if (dp[level] != -1)
    {
        return dp[level];
    }
    int ans = 1e9;
    for (int i = 1; i <= k; i++)
    {
        if (level - i >= 0)
        {
            ans = min(ans, rec(level - i) + abs(v[level] - v[level - i]));
        }
    }
    return dp[level] = ans;
}

signed main()
{
    IOS
            cin >>
        n >> k;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(n - 1) << endl;
}
