/*uestion
You are given an array A of N integers and an integer K. Find the number of pairs (i, j) such that i < j and abs(Ai - Aj) = K
*/

// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     int arr[n];
//     unordered_map<int,int>mp;
//     int ans=0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//         mp[arr[i]]++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         mp[arr[i]]--;

//         ans += mp[arr[i] + k];
//         if(k){                  //it will work now when k=0
//             ans += mp[arr[i] - k];
//         }
//     }

//     cout<<ans<<'\n';
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
#define int long long
void solve()
{
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> mp;
    int ans = 0;

    while (n--)
    {
        int x;
        cin >> x;
        // if(mp.find(x+k)!=mp.end()){
        //     ans+=mp[x+k];
        // }
        // if(k){
        //     if (mp.find(x - k) != mp.end()){
        //         ans+=mp[x-k];
        //     }
        // }
        if (mp[x + k])
        {
            ans += mp[x + k];
        }
        if (k) //for the k=0 condition we can simply use this check
        { 
            if (mp[x - k])
            {
                ans += mp[x - k];
            }
        }
        mp[x]++;
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
