#include<bits/stdc++.h>
using namespace std;
#define int long long       //value sum can exceed 10^9 range so keep it long long
int n,w;
int warr[101];
int value[101];
int dp[101][100100];
int rec(int level, int taken){
    if(level==n){
        return 0;
    }

    if(dp[level][taken]!=-1){
        return dp[level][taken];
    }
    int ans=0;
    ans=rec(level+1,taken);

    if(taken+warr[level]<=w){
        ans=max(ans, rec(level+1,taken+warr[level])+value[level]);
    }
    return dp[level][taken]=ans;
}
void solve(){
    cin>>n>>w; 
    for (int i = 0; i < n; i++)
    {
        cin>>warr[i]>>value[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}