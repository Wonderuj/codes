// https://www.youtube.com/watch?v=BBzO1XLejzk


// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// vector<vector<int>>g;
// vector<int>vis;
// vector<int>components;
// vector<int>suffix;

// void dfs(int node, int comp){
//     vis[node]=comp;
//     for(auto v: g[node]){
//         if(!vis[v]){
//             dfs(v,comp);
//         }
//     }
//     components[comp]++;
//     suffix[comp]++;
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     g.resize(n + 1);
//     vis.assign(n+1,0);
//     components.assign(n+1,0);
//     suffix.assign(n+1,0);
//     for(int i=0;i<m;i++){
//         int a,b;
//         cin>>a>>b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }
//     int comp=0;
//     for(int i=1;i<=n;i++){
//         if(!vis[i]){
//             comp++;
//             dfs(i,comp);
//         }
//     }

//     for(int i=n-1;i>0;i--){
//         suffix[i]+=suffix[i+1];
//     }
//     int ans=0;
//     for (auto v : components)
//     {
//         cout << v << " ";
//     }
//     cout << '\n';

//     for(auto v:suffix){
//         cout<<v<<" ";
//     }
//     cout<<'\n';
//     for(int i=1;i<n;i++){
//         ans+=components[i]*suffix[i+1];
//     }
//     cout<<ans<<'\n';
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;
vector<int> vis;
vector<int> components;

void dfs(int node, int comp)
{
    vis[node] = comp;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v, comp);
        }
    }
    components[comp]++;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    components.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            comp++;
            dfs(i, comp);
        }
    }

    int sum = n;  // n are total number of nodes- it will act like a suffix sum for us
    int ans=0;
    for (auto v : components)
    {
        sum-=v;     
    //substracting current number of nodes in this component to get suffix sum till start.
        ans+=v*sum; 
    //number of nodes * number of nodes that are remaining (suffix sum) will give number of connections current component can make
    }

    cout << ans << '\n';
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}

//Using Permutations and combinations 
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// vector<vector<int>> g;
// vector<int> vis;
// vector<int> components;

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
//     components[comp]++;
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     g.resize(n + 1);
//     vis.assign(n + 1, 0);
//     components.assign(n + 1, 0);

//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
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

//     int total = (n * (n - 1)) / 2; // nC2 - choosing any 2 nodes of all
//     for (auto v : components)
//     {
//         total -= (v * (v - 1)) / 2;
//         // subtracting the case when both nodes are chosen from same component
//     }

//     cout << total << '\n';
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }