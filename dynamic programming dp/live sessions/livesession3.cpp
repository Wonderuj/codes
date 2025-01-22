// // how many strings can be made of length <=N which contain T(any other given string) as subsequence

// #include<bits/stdc++.h>
// using namespace std;
// int n;
// string t;
// int dp[1001][1001];
// int rec(int i, int x){

//     //base case
//     if(i==n){
//         if(x==t.length()){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     int ans=0;
//     //caching
//     if(dp[i][x]!=-1){
//         return dp[i][x];
//     }
//     //transition

//     if(x==t.length()){
//         ans=1+26*rec(i+1,x);       //if we want to form strings of exactly of length N then ans= 26*rec(i+1,x) only as we dont have to add 1 each time of forming strings of less size
//     }
//     else{
//         ans = rec(i + 1, x + 1) + (25 * rec(i + 1, x));
//     }
//     return dp[i][x]=ans;
// }

// void solve(){
//     cin>>n>>t;
//     memset(dp,-1,sizeof(dp));
//     cout<<rec(0,0)<<endl;

// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }

//---------------------------------------------------------------------------------------------------------------------------

// Q2) How many strings can be formed which does not contain this perticular substring "01001"

#include <bits/stdc++.h>
using namespace std;
int n;
string t = "01001";
int dp[1001][1001];
int rec(int i, int x)
{
    // base case
    if (x == 5)
    {
        return 0;        //we have the substring so sting will not to be counted
    }
    if (i == n)
    {
        return 1; // if we are at end of our string and havent seen sting t yet then we are good to go
    }

    // automata
    int ans = 0;
    if (dp[i][x] != -1)
    {
        return dp[i][x];
    }

    if (x == 0)
    {                                        // place 0  + place 1
        ans = rec(i + 1, 1) + rec(i + 1, 0); // if we placed 0 we will go to first position or we placed 1 then we will remain at same x but at next level
    }
    else if (x == 1)
    {
        ans = rec(i + 1, 1) + rec(i + 1, 2); // if we placed a 0 we will remain at 1 (as first char 0 will be there so we already be at 1st state)
    }
    else if (x == 2)
    {
        ans = rec(i + 1, 3) + rec(i + 1, 0);
    }
    else if (x == 3)
    {
        ans = rec(i + 1, 4) + rec(i + 1, 2);
    }
    else if (x == 4)
    {
        ans = rec(i + 1, 1) + rec(i + 1, 5);
    }
    return dp[i][x] = ans;
}
void solve()
{
    cin >> n;
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