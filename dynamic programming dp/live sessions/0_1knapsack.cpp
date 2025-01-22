// Knapsack problem. first without dp. doing a brute force solution and then optimising it

// #include<bits/stdc++.h>
// using namespace std;
// int n,wlimit;
// int p[101];
// int w[101];

// int rec(int i, int wtaken){
//     //base case
//     if(i==n){
//         return 0;    //we cant get any profit after reaching end point(as no item is left) hence we return 0.
//     }

//     //trasnsition
//     int ans= rec(i+1, wtaken);          //on not taking the item go into recursion of next level and get me the answer.

//     if(wtaken+w[i]<=wlimit){  //if we can take the item - (doing this helps us to not go into invalid cases and saves us from pruning manually)
//         ans=max(ans, rec(i+1,wtaken+w[i])+p[i]);
//     }
//     //return
//     return ans;
// }
// void solve(){
//     cin>>n>>wlimit;
//     for(int i=0;i<n;i++){
//         cin>>p[i]>>w[i];
//     }
//     cout << rec(0, 0) << endl; // This rec(0,0) tells that:
//     // I am starting at first item so everything from 0 to n-1 is left and I have not taken anything(2nd zero of that)=> initial starting point
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }
// //this brute force soltuion will have complexity of O(N*2^N) - N is depth of recursion on worse case and 2^N branching will have happend that time.

//---------------------------------------------------------------------------------------------

// dp soltuion/ optimization

// #include <bits/stdc++.h>
// using namespace std;
// int n, wlimit;
// int p[101];
// int w[101];
// // 1) declare the dp
// int dp[101][10010]; // states can go till 100 and w taken till 10^4 (constraints of question assumed)
// int rec(int i, int wtaken)
// {
//     // base case
//     if (i == n)
//     {
//         return 0; // we cant get any profit after reaching end point(as no item is left) hence we return 0.
//     }

// // 3) Cache check
//     if (dp[i][wtaken] != -1)
//     {
//         return dp[i][wtaken];
//     }
//     // trasnsition
//     int ans = rec(i + 1, wtaken); // on not taking the item go into recursion of next level and get me the answer.

//     if (wtaken + w[i] <= wlimit)
//     { // if we can take the item - (doing this helps us to not go into invalid cases and saves us from pruning manually)
//         ans = max(ans, rec(i + 1, wtaken + w[i]) + p[i]);
//     }

// // 4) save and return
//     return dp[i][wtaken] = ans;
// }
// void solve()
// {
//     cin >> n >> wlimit;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> p[i] >> w[i];
//     }

// //2) Setting DP's initial value to -1 (here 0 or some positive answer can be returned so -1 is a good choice for dp initals)
//     memset(dp, -1, sizeof(dp));

//     cout << rec(0, 0) << endl; // This rec(0,0) tells that:
//     // I am starting at first item so everything from 0 to n-1 is left and I have not taken anything(2nd zero of that)=> initial starting point
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }

// now this dp soltuion have a complexity of O(W*N)

//-----------------------------------------------------------------------------------------------

//Knapsack with twist of restiriction of atmost k items to be selected

#include <bits/stdc++.h>
using namespace std;
int n, wlimit,klimit;
int p[101];
int w[101];
// 1) declare the dp
int dp[101][1001][101]; // states can go till 100 and w taken till 10^4 (constraints of question assumed)
int rec(int i, int wtaken, int taken)
{
    // base case
    if (i == n)
    {
        return 0; // we cant get any profit after reaching end point(as no item is left) hence we return 0.
    }

    // 3) Cache check
    if (dp[i][wtaken][taken] != -1)
    {
        return dp[i][wtaken][taken];
    }
    // trasnsition
    int ans = rec(i + 1, wtaken,taken); // on not taking the item go into recursion of next level and get me the answer.

    if (wtaken + w[i] <= wlimit  && taken+1<=klimit)
    { // if we can take the item - (doing this helps us to not go into invalid cases and saves us from pruning manually)
        ans = max(ans, rec(i + 1, wtaken + w[i], taken + 1) + p[i]);
    }

    // 4) save and return
    return dp[i][wtaken][taken] = ans;
}

void printsol(int i, int wtaken, int taken)
{ // to print the indexs of items taken

    //base case here is necessary too. 
    if(i==n){
        return;
    }
    int optimal = rec(i, wtaken, taken);

    if (wtaken + w[i] <= wlimit && optimal == rec(i + 1, wtaken + w[i], taken + 1) + p[i]){
        //then its best to take
        cout<<i<<" ";
        printsol(i+1, wtaken+w[i], taken+1);
    }
    else{
        //best to not take
        printsol(i+1,wtaken,taken);
    }
}
void solve()
{
    cin >> n >> wlimit>>klimit;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> w[i];
    }

    // 2) Setting DP's initial value to -1 (here 0 or some positive answer can be returned so -1 is a good choice for dp initals)
    memset(dp, -1, sizeof(dp));

    cout << rec(0, 0,0) << endl; // This rec(0,0) tells that:
    // I am starting at first item so everything from 0 to n-1 is left and I have not taken anything(2nd zero of that)=> initial starting point
    printsol(0,0,0);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}

/*
sample input
4 6 3
2 1
4 5
3 2
4 4

solution- 
7
2 3


*/