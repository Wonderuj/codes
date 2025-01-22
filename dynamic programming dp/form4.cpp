#include<bits/stdc++.h>
using namespace std;
int n;
int arr[2020];
int dp[2020][2020];
bool done[2020][2020];

int rec(int l, int r){
    //base case
    if(l==r){
        return arr[l];
    }

    //cache check 
    if(done[l][r]){
        return dp[l][r];
    }
    //compute and save
    int ans= max(arr[l]-rec(l+1,r), arr[r]-rec(l,r-1));
    done[l][r]=1;
    return dp[l][r]=ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            done[i][j]=0;
        }                                               //doing this to reset the flag for multiple test cases
    }
    cout<<rec(0,n-1)<<endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}