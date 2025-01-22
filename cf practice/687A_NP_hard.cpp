#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vpii vector<pii>
#define vvi vector<vi>
#define printArr(a, start, end)for(int i=start ; i<end ; ++i)cout << a[i] << " ";
#define readArr(a, start, end)for(int i=start ; i<end ; ++i)cin >> a[i];
#define read2D(mat, n, m)for(int i=0 ; i<n ; ++i)for(int j=0 ; j<m ; ++j)cin >> mat[i][j];
#define F first
#define S second
#define B begin()
#define E end()
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define len(x) (int)x.length()
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a)) 
#define repn(a, b, c) for (int(a) = (b); (a) <= (c); ++(a)) 
#define repd(a, b, c) for (int(a) = (b); (a) >= (c); --(a)) 
#define repauto(a, b) for (auto&(a) : (b)) 
#define int long long

const int MOD = 1e9 + 7;  

vi g[100100];
bool col[100100];
bool vis[100100];

bool possible=1;

void dfs(int node, int c){
    if(vis[node]) return;
    vis[node]=1;
    col[node]=c;

    for(auto x:g[node]){
        if(!vis[x]){
            dfs(x,c^1);
        }
        else{ //checking if colour of this adjacent node x is same is current colour, then it won't be bipartite
            if(c==col[x]){
                possible=0;
            }
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].pb(v);
        g[v].pb(u);
    }

    rep(i,0,n){
        if(!vis[i]) dfs(i,0);
    }

    if(possible){
        int cnt[2]={0};
        for(int i=0;i<n;i++){
            ++cnt[col[i]];
        }

        cout<<cnt[0]<<endl;
        rep(i,0,n){
            if(col[i]==0) cout<<i+1<<" ";
        }
        cout<<'\n'<<cnt[1]<<'\n';
        rep(i,0,n){
            if(col[i]==1) cout<<i+1<<" ";
        }
    }
    else cout<<-1<<endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}