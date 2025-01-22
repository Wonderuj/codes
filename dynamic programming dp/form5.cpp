#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> moves = {1, 3, 4};
int dp[100100];
int rec(int x)
{
    if (x == 0)
    {
        return 0;
    }

    if (dp[x] != -1)
    {
        return dp[x];
    }

    int ans = 0;
    for (auto v : moves)
    {
        if (v <= x && rec(x - v) == 0) // if there is a valid move to make(v<=x) and we can make opponent reach a losing state rec(x-v) then return win
        {
            ans = 1;
            break;
        }
    }
    return dp[x] = ans;
}
void solve()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(n) << endl;

    // to check for the pattern print the output from 1 to n
    // for (int i = 0; i <= 20; i++)
    // {
    //     cout << i << " " << rec(i) << endl;
    // }
    // // we see the pattern as 0101111
    // // so we can code it as O(1) after that
    // if (n % 7 == 0 || n % 7 == 2)   ///0 and 2nd index gave 0 that means we will lose with that
    // {
    //     cout << "lose\n";
    // }
    // else
    // {
    //     cout << "win\n";
    // }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}