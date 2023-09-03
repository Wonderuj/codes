// #include <bits/stdc++.h>
// using namespace std;
// #define pb push_back

// vector<vector<int>> g;
// vector<int>col;
// vector<int>parent;
// bool bipart=true;
// void dfs(int node,int colour, int par){
//     parent[node]=par;
//     col[node]=colour;

//     for(auto v:g[node]){
//         if(v==parent[node]){
//             continue;
//         }

//         if(!col[v]){
//             dfs(v,col[node]^3,node);
//         }

//         if(col[v]==col[parent[node]]){
//             bipart=false;
//         }

//     }
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     g.resize(n + 1);
//     col.assign(n+1,0);
//     parent.assign(n+1,0);
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].pb(b);
//         g[b].pb(a);
//     }

//     for (int i = 1; i <= n; i++)
//     {

//         if (!col[i])
//         {
//             dfs(i,1,0);
//         }
//     }
//     if(bipart){
//         cout<<"YES\n";
//     }
//     else{
//         cout<<"NO\n";
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

//---------------------------------------------------------------------------------------
// In this question we wanted to find wheather graph is a bipartite or not, it can be done by BFS and DFS both..

// 1) BFS

// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> g;
// vector<int> col;

// bool bfs(int node)
// {
//     col[node] = 0;
//     queue<int> q;
//     q.push(node);
//     while (!q.empty())
//     {
//         int cur = q.front();
//         q.pop();
//         // cout << "I was at front " << cur << " with colour: " << col[cur] << endl;
//         for (auto v : g[cur])
//         {
//             // cout << "checking the neighbour " << v << " it have colour " << col[v] << endl;
//             if (col[v] != -1)
//             { // already coloured
//                 if (col[v] == col[cur])
//                 {
//                     // cout << "I am same colour as previous " << v << " : " << cur << endl;
//                     return false;
//                 }
//             }
//             else
//             { // colouring with diffrent colour than the current node
//                 // cout << "I am different colour as previous " << v << " : " << cur << endl;
//                 col[v] = (col[cur] == 0) ? 1 : 0;
//                 q.push(v);
//             }
//         }
//     }
//     return true;
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     g.resize(n + 1);
//     col.assign(n + 1, -1);
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }

//     bool bipart = true;
//     for (int i = 1; i <= n; i++)
//     {
//         if (col[i] == -1)
//         {
//             // cout<<"I am uncoloured. Bfs start at "<<i<<endl;
//             bipart = bfs(i);
//             if(bipart==false){   //this condition I was missing this break case earlier..
//                 break;
//             } // Let's say the graph is not connected. So bipartite variable depends only on the last component of the graph explored.
//             // You need to break as soon as you get bipartite false for the first time.
//         }
//     }

//     string s = (bipart == true) ? "YES" : "NO";
//     cout << s << '\n';
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t;
//     // cin >> _t;
//     // while (_t--)
//     solve();
// }


//---------------------------------------------

//2) DFS approach

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<int>col;
bool bipart=true;

bool dfs(int node, bool colour){
    col[node] = colour;
    for(auto v: g[node]){
        if(col[v]!=-1){
            if(col[v]==col[node]){
                return false;
            }
        }
        else{
            if (!dfs(v, (col[node] == 0) ? 1 : 0))
            {
                return false; // Propagate false result up the call stack
            }
        }
    }
    return true;
}


void solve(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            bipart= dfs(i,0);
            if(!bipart){
                break;
            }
        }
    }

    string s = (bipart == true) ? "YES" : "NO";
        cout << s << '\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}

