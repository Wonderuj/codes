#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
int arr[100100];
int dp[100100];

int rec(int level){         //min score to reach from 1 to level
    //base case and prunung
    if(level<=0){
        return 0;
    }

    //cache check
    if(dp[level]!=-1){
        return dp[level];
    }

    //compute
    int cost1,cost2;
        if (level > 1)
        {
        cost2 = (rec(level - 2) + abs(arr[level] - arr[level - 2]));
        cost1 = (rec(level - 1) + abs(arr[level] - arr[level - 1]));
        }
        if(level==1){
            cost1=abs(arr[0]-arr[1]);
            cost2=cost1;
        }
        
    
    int ans= min(cost1, cost2);
    return dp[level] =ans;
}


void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}