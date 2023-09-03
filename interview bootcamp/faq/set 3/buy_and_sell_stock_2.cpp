/*
While traversing through the array, update the minimum price. If the current price is greater than the price a day before, update the profit. While calculating the profit in this way, we made sure that there was no better price to buy from the past

For stock prices that are strictly decreasing, you don’t do any transaction.

Time Complexity per test case: O(N)*/

#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

long long BuyAndSellStock(vector<int> &a)
{
    int n=a.size();
    int ans=0;
    for(int i=0;i<n-1;i++){
        ans+= max(0,a[i+1]-a[i]);
    }
    return ans;
}

int main()
{
    IOS

        int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        cout << BuyAndSellStock(a) << "\n";
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS                  \
//     ios::sync_with_stdio(0); \
//     cin.tie(0);              \
//     cout.tie(0);

// int n;
// int dp[100010][2];
// int rec(int level, bool st, vector<int> &a)
// {
//     n = a.size();
//     if (level == n &&st==0)
//     {
//         return 0;
//     }
//     if (dp[level][st] != -1)
//     {
//         return dp[level][st];
//     }

//     int ans = 0;
//     if (st == 0)
//     {
//         ans += max(rec(level + 1, 0, a), rec(level + 1, 1, a) + a[level+1]);
//     }
//     else{
//         ans += max(rec(level + 1, 1, a), rec(level + 1, 0, a) - a[level+1]);
//     }
//     return ans=dp[level][st];
// }
// long long BuyAndSellStock(vector<int> &a)
// {
//     n = a.size();
//     for(int i=0;i<n;i++){
//         for(int j=0;j<2;j++){
//             dp[i][j]=-1;
//         }    
//     }
//     int profit=rec(n,0,a);
//     return profit;
// }

// signed main()
// {
//     IOS

//         int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;

//         vector<int> a(n);

//         for (int i = 0; i < n; ++i)
//         {
//             cin >> a[i];
//         }

//         cout << BuyAndSellStock(a) << "\n";
//     }

//     return 0;
// }