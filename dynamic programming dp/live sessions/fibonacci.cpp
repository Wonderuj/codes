// #include<bits/stdc++.h>
// using namespace std;
// int fib(int n){
//     if(n<=1){
//         return n;
//     }
//     else{
//         return fib(n-1)+fib(n-2);
//     }
// }
// void solve(){
//     int n; cin>>n;
//     cout<<fib(n)<<endl;
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }   without dp

//with DP

#include<bits/stdc++.h>
using namespace std;
int dp[100100];
int fib(int n){
    if(n<=1){
        return n;
    }

    //if we have value saved?
    if(dp[n]!=-1){
        return dp[n];
    }
    else{  //compute the value
        return dp[n]= fib(n-1)+fib(n-2);
    }
}
void solve(){
    int n; cin>>n;
    memset(dp, -1, sizeof(dp));
    cout<<fib(n)<<endl;
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
} 