#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 20;
int n, m;
vector<bool> vis(N);
vector<int> g[N][N];
void dfs(int node, int c)
{
    vis[node] = true;
    for (auto &neigh : g[node][c])
    {
        if (!vis[neigh])
            dfs(neigh, c);
    }
}

void solve()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g[u][c].push_back(v);
        g[v][c].push_back(u);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int counter = 0;
        int u, v;
        cin >> u >> v;
        for (int c = 1; c <= m; c++)
        {
            for (int i = 1; i <= n; i++)
                vis[i] = false;

            dfs(u, c);
            if (vis[v])
                counter++;
        }
        cout << counter << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}