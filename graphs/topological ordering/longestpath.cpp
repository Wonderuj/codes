// //we can to topological ordering on a DAG using DP

// #include<bits/stdc++.h>
// using namespace std;
// vector<vector<int>>g;
// int dp[100100];

// int rec(int node){      // dp returns longesst path starting a node
//     if(dp[node]!=-1){
//         return dp[node];
//     }
//     int ans=1;

//     for(auto v:g[node]){
//         ans=max(ans, 1+rec(v));
//     }
//     return dp[node]=ans;

// }
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     g.resize(n+1);
//     for(int i=0;i<n;i++){
//         int a,b;
//         cin>>a>>b;
//         g[a].push_back(b);
//     }
//     memset(dp,-1,sizeof(dp));
//     int ans=0;
//     for(int i=1;i<=n;i++){
//         ans=max(ans,rec(i));
//     }
//     cout<<ans<<endl;

// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }

//-------------------------------------------------------------------------------------------------------------------------
// topo longest path using dfs

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>>g;
vector<int>vis;
vector<int>topo;
int dp[100100];
void dfs(int node){
    vis[node]=1;
    for(auto v: g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
    topo.push_back(node);
}
void solve()
{
    cin >> n >> m;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    //reverse(topo.begin(), topo.end());
    // for(auto v: topo){
    //     cout<<v<<" ";
    // }
    int final =0;
    for(auto node:topo){
        int ans=1;
        for(auto v:g[node]){
            ans=max(ans,1+dp[v]);
        }
        dp[node]=ans;
        final=max(final,dp[node]);
    }
    
    cout<<final<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}