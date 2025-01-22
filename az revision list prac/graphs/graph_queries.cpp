/*Question
You have given an undirected graph G with N nodes and M edges. You've to answer Q queries. Each query is either of the following two types:

1 X: Print the size of the connected components containing node X.
2 X Y: Print ‘YES’ (without quotes) if node X and Y belong to the same connected component, else print ‘NO’ (without quotes).

*/

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<vector<int>>g;
vector<int>vis;
vector<vector<int>>components;
void dfs(int node, int comp){
    vis[node]=comp;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,comp);
        }
    }
    components[comp].pb(node);
}

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    g.resize(n+1);
    vis.assign(n+1,0);
    components.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int comp=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            comp++;
            dfs(i,comp);
        }
    }

    while(q--){
        int a;
        cin>>a;
        if(a==1){
            int x;
            cin>>x;
            cout<<components[vis[x]].size()<<'\n';
        }
        else{
            int x,y;
            cin>>x>>y;
            string s= (vis[x]==vis[y])?"YES\n":"NO\n";
            cout<<s;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}

// #include <bits/stdc++.h>
// using namespace std;
// #define pb push_back
// vector<vector<int>> g;
// vector<int> vis;
// vector<int> id;
// void dfs(int node, int comp)
// {
//     vis[node] = comp;
//     for (auto v : g[node])
//     {
//         if (!vis[v])
//         {
//             dfs(v, comp);
//         }
//     }
//     components[comp].pb(node);
// }

// void solve()
// {
//     int n, m, q;
//     cin >> n >> m >> q;
//     g.resize(n + 1);
//     vis.assign(n + 1, 0);
//     id.resize(n + 1);
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].pb(b);
//         g[b].pb(a);
//     }
//     int comp = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (!vis[i])
//         {
//             comp++;
//             dfs(i, comp);
//         }
//     }

//     while (q--)
//     {
//         int a;
//         cin >> a;
//         if (a == 1)
//         {
//             int x;
//             cin >> x;
//             cout << components[vis[x]].size() << '\n';
//         }
//         else
//         {
//             int x, y;
//             cin >> x >> y;
//             string s = (vis[x] == vis[y]) ? "YES\n" : "NO\n";
//             cout << s;
//         }
//     }
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }