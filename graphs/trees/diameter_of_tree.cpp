#include <bits/stdc++.h>
using namespace std;
vector<int> g[200100];
int par[200100];
int dep[200100];

void dfs(int node, int parent, int depth)
{
    par[node] = parent;
    dep[node] = depth;

    for (auto v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node, depth + 1);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    int maxchl = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dep[i] > dep[maxchl])
        {
            maxchl = i;
        }
    }
    cout << maxchl << endl;
    dfs(maxchl, 0, 0);
    int maxchl2 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dep[i] > dep[maxchl2])
        {
            maxchl2 = i;
        }
    }
    cout << dep[maxchl2] << '\n';
    cout << maxchl2 << '\n';

    int j = maxchl2;

    vector<int> path;
    while (j != maxchl)
    {
        path.push_back(j);
        j = par[j];
    }
    path.push_back(j);
    reverse(path.begin(), path.end());
    for (auto v : path)
    {
        cout << v << " ";
    }
    cout << '\n';
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}


