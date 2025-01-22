#include<bits/stdc++.h>
using namespace std;
int n,m; 
int x,y;            //insertion cost x and deletion cost y
string a,b;
int cost[26][26];
int dp[1001][1001];

int rec(int i, int j){
    //base case
    if(i==n){
        return (m-j)*x;       //if string a is finished so we will add remaining elements in the end of it. 
                //since m are total elements in b and j is current index, so remaining elemets will be m-j and multiply with cost x to get total cost of insertion at end.
    }

    if(j==m){           //second string finished so we're gonna delete the remaining elements from first string
        return (n-i)*y;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans=1e9;
    //insert in front of A
    ans=min(ans, x+rec(i,j+1));         //inserting and since char at j will be matched, we move one step ahead in b string and check for current ith element again 
    //delete in  front of A
    ans=min(ans, y+rec(i+1,j));
    //transform front of A to front of B
    ans=min(ans, cost[a[i]-'a'][b[i]-'a']+rec(i+1,j+1)); 
                    //this -'a' is for 0 indeing of array. the current char will be at 0 indexed position. a will be at 0.
    return dp[i][j]= ans;
}
void solve(){
    cin>>n>>m;
    cin>>a>>b;
    cin>>x>>y;
    for(int i=0;i<26;i++){
        for (int j = 0; j< 26; j++){
            cin>>cost[i][j];
        }
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