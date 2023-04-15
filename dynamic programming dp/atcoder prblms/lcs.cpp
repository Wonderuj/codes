#include <bits/stdc++.h>
using namespace std;
string s, p;
int dp[3030][3030];

int rec(int l1, int l2)
{
    int n = s.size();
    int m = p.size();

    if (l1 == n || l2 == m)
    {
        return 0;
    }
    if (dp[l1][l2] != -1)
    {
        return dp[l1][l2];
    }

    int ans = 0;
    if (s[l1] == p[l2])
    {

        ans = max(ans, 1 + rec(l1 + 1, l2 + 1));
    }
    else
    {
        ans = max(rec(l1 + 1, l2), rec(l1, l2 + 1));
    }
    return dp[l1][l2] = ans;
}
void solve()
{
    cin >> s >> p;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}

///////modifying it to printing setup

// #include <bits/stdc++.h>
// using namespace std;
// #define MP make_pair
// string s, p;
// int n,m;
// int dp[3030][3030];
// pair<int, int> back[3030][3030];

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
//     if (s[l1] == p[l2])
//     {

//         ans = max(ans, 1 + rec(l1 + 1, l2 + 1));
//         back[l1][l2] = MP(l1, l2);
//     }
//     else
//     {
//         ans = max(rec(l1 + 1, l2), rec(l1, l2 + 1));
//         if (rec(l1 + 1, l2) > rec(l1, l2 + 1))
//         {
//             back[l1][l2] = MP(l1 + 1, l2);
//         }
//         else
//         {
//             back[l1][l2] = MP(l1, l2 + 1);
//         }
//     }
//     return dp[l1][l2] = ans;
// }
// void generate(int l1,int l2){
//     if (l1 == n || l2 == m)
//     {
//         return;
//     }

//     string final="";
//     if (s[l1] == p[l2])
//     {

        
//         final.append(back)
//     }
// }
// void solve()
// {
//     n = s.size();
//      m = p.size();
//     cin >> s >> p;
//     memset(dp, -1, sizeof(dp));
//     cout << rec(0, 0) << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }