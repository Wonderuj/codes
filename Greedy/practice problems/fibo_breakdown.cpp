#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(), a.end()
vector<int> dp(50);
int rec(int n)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = rec(n - 1) + rec(n - 2);
    return dp[n] = ans;
}
int left(int x)
{
    int sum = 0;
    while (x != 0)
    {
        auto it = upper_bound(all(dp), x);
        it--;
        x = x - *it;
        sum++;
    }
    return sum;
}
void solve()
{
    int k;
    cin >> k;
    for(int i=0;i<50;i++) dp[i]=-1;
    for (int i = 0; i <= 49; i++)
    {
        rec(i);
    }
    int final = left(k);
    cout << final << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}   




//-------------------------------------
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define all(a) a.begin(), a.end()

// void solve()
// {
//     int k;
//     cin >> k;
//     vector<int> fib(50);
//     fib[0] = 0;
//     fib[1] = 1;
//     for (int i = 2; i < 50; i++)
//     fib[i] = fib[i - 1] + fib[i - 2];
//     int ans = 0;
//     while (k != 0)
//     {
//     auto it = upper_bound(all(fib), k);
//     it--;
//     k = k - *it;
//     ans++;
//     }
//     cout << ans << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }

//-----------
// #include <bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     int k;
//     cin >> k;
//     multiset<long long> mt;
//     long long first = 1;
//     long long second = 1;
//     mt.insert(first);
//     mt.insert(second);
//     for (int i = 2; i <= 50; i++)
//     {
//         long long temp = first;
//         first = second;
//         second = temp + second;
//         mt.insert(second);
//     }
//     int ans = 0;
//     while (k != 0)
//     {
//         auto it = mt.upper_bound(k);
//         it--;
//         k = k - (*it);
//         ans++;
//     }
//     cout << ans << "\n";
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
// }