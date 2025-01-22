//#convex ploygon
#include<bits/stdc++.h>
using namespace std;
int n;
int x[101]; int y[101];
int dp[101][101];

int sq(int x){
    return x*x;
}
int dist(int i, int j){
    return sq(x[i]-x[j])+sq(y[i]-y[j]);             //we need square of length of diagnol, so no need to square root it
}
int rec(int l, int r){
    //base case
    if(r-l<3) return 0;     //or r-l+1<=3  //<3 points bw them so, its either a line or triangle. hence no triangulation required there, so returning 0
                                //number of points including r and l is less than 3 so return 0
    //cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    //transition
    int ans=1e9;
    ans=min(ans, rec(l+1,r)+ dist(l+1,r));         //case of triangle handeled seperateely as only one of the distance will be added to recurance diagnol cost
    ans = min(ans, rec(l, r-1) + dist(l, r-1));

    for(int x=l+2;x<=r-2;x++){
        ans=min(ans, rec(l,x)+rec(r,x)+dist(l,x)+dist(r,x));            
    }

    //save and return 
    return dp[l][r]=ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];   //input of x and y coordinates   
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}