//on an explicit graph (when nodes and neighbours are given as input)

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define rep0(i, n, m) for (int i = n; i < m; i++)
#define rep1(i, n, m) for (int i = n; i <= m; i++)
#define F first
#define S second
#define pb push_back
using ii = pair<int, int>;
 /*
 6 6
 1 2
 2 3
 3 4
 1 4
 4 5
 4 6
 1
 6 
ans is 2 as from 1 we can go to 4 and from 4 we can go to 6
 */

int n,m;
vvi g;

int dist[100100];
void bfs(int st){
    rep1(i,0,n){
        dist[i]=1e9;
    }
    dist[st]=0;
    queue<int>q;
    q.push(st);
    while(!q.empty()){
        int cur =q.front();
        q.pop();
        for(auto v:g[cur]){
            if(dist[v]>dist[cur]+1){
                dist[v]=dist[cur]+1;
                q.push(v);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    rep0(i,0,m){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
    }
    int st,en;
    cin>>st>>en;
    bfs(st);
    cout<<dist[en]<<endl;

}   
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}