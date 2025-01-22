#include<bits/stdc++.h>
using namespace std;
int n;
int p[1010];
int dp[1010][1010];
int rec(int l, int r){
    if(l+1==r){                         //when its last part and we cant break it any further.x
        return 0;
    }
    if(dp[l][r]!=-1) return dp[l][r];
    int ans=1e9;
    for(int mid=l+1;mid<=r-1;mid++){
        ans=min(ans, p[r]-p[l]+rec(l,mid)+rec(mid,r));
    }
    return dp[l][r]=ans;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];              
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,n)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}