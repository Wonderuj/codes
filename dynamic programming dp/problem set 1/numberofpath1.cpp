#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define endl '\n'
int n,m;
int arr[1010][1010];
int dp[1010][1010];
int rec(int i, int j){
    //pruning
    if (i < 1 || i>n||j>m|| j < 1|| arr[i][j]==1)
    {
        return 0;
    }

    //base case
    if(i==1 && j==1){
        return 1;            //I am going reverse way. paths ending at i,j so it will make path and on base will hit 1,1
    }
    if(dp[i][j]!=-1) return dp[i][j];
    //computation
    int ans=0;

    ans= (rec(i-1,j)%mod +rec(i,j-1)%mod)%mod;

    return dp[i][j]=ans;
    
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    // if(arr[1][1]==1 || arr[n][m]==1){
    //     cout<<'0'<<endl;
    // } else
    {   
        cout << rec(n, m) << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}