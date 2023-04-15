#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,m;
int arr[1001][1001];
int dp[1001][1001];
                                                 //this solution is in form 2 where dp(i,j) means max path sum from 1,1 to i,j
                                                //for form 1 dp(1,j) can mean max path sum from i, j to n,m
int rec(int r, int c){
   //pruning
    if(r<0 || c<0|| r>n||c>m){
        return 0;
    }

    //base case
    if(r==1 && c==1){
        return arr[1][1];
    }

    if(dp[r][c]!=-1){
        return dp[r][c];
    }

    long long ans= arr[1][1];
    ans= max(rec(r-1,c), rec(r,c-1))+arr[r][c];
    return dp[r][c]=ans;
}

void solve(){
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
       for (int j =1; j <= m; j++)
       {
            cin>>arr[i][j];
            dp[i][j]=-1;
       }
       
    }
    cout<<rec(n,m)<<endl;

    for (int i = 1; i <= n; i++)
    {
       for (int j = 1; j <= m; j++)
       {
            dp[i][j] = -1;
       }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}

