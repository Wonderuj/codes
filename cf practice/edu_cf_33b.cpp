// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 20;
// vector<int> g[N];
// vector<bool> vis(N);
// vector<int> gold(N);

// void dfs(int node, int &goldmin)
// {
//     vis[node] = true;
//     goldmin = min(goldmin, gold[node]);
//     for (auto &x : g[node])
//     {
//         if (!vis[x])
//         {
//             dfs(node, goldmin);
//         }
//     }
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     for (int i = 1; i <= n; i++)
//     {
//         cin >> gold[i];
//     }

//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }

//     int sum = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         int goldcomp = gold[i];
//         if (!vis[i])
//         {
//             dfs(i, goldcomp);
//         }
//         sum += goldcomp;
//     }
//     cout << sum << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int _t; cin>>_t;while(_t--)
//     solve();
// }

/*
3
5 2
2 5 3 4 8
1 4
4 5
10 0
1 2 3 4 5 6 7 8 9 10
10 5
1 6 2 7 3 8 4 9 5 10
1 2
3 4
5 6
7 8
9 10

*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define int long long
const int N = 1000 * 100 + 20;

vvi g;
vi gold;
vector<bool> vis;

void dfs(int node, int& goldmin){
    vis[node]=true;
    goldmin=min(goldmin,gold[node]);
    // cout<<"goldmin "<< goldmin<<" node "<<node<<endl;
    for(auto x:g[node]){
        if(!vis[x]){
            dfs(x,goldmin);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    vis.assign(n + 2, false);
    gold.assign(n + 2,0);

    for (int i = 1; i <= n; i++)
    {
        cin >> gold[i];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int goldcomp = gold[i];
        if (!vis[i])
        {
            dfs(i, goldcomp);
            // cout << "goldcomp " << goldcomp << " node " << i << endl;
            sum+=goldcomp;
        }
    }
    cout<<sum<<endl;
    
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
    g.clear();
    vis.clear();
}