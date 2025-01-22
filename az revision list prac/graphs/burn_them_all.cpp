#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define MP make_pair
#define F first
#define S second
#define pb push_back
#define int long long

int n, m;
vector<vector<ii>> g;
vector<int> vis;
vector<int> dist;
vector<vector<int>> edges;
void dijkstra(int st)
{
    dist[st] = 0;
    priority_queue<ii> pq;
    pq.push({-0, st});
    while (!pq.empty())
    {
        ii cur = pq.top();
        pq.pop();

        if (vis[cur.S])
            continue;
        vis[cur.S] = 1;

        for (auto v : g[cur.S])
        {
            int neigh = v.F;
            int wt = v.S;
            if (dist[neigh] > dist[cur.S] + wt)
            {
                dist[neigh] = dist[cur.S] + wt;
                pq.push({-dist[neigh], neigh});
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    dist.assign(n + 1, 1e18);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        g[u].pb({v, d});
        g[v].pb({u, d});
        edges.pb({u, v, d});
    }

    int st;
    cin >> st;
    dijkstra(st);

    // int ans =-1e18;

    // for (auto it : edges)
    // {
    //     ans = max(ans, (dist[it[0]] + dist[it[1]] + it[2]) / 2);
    // }
    // cout << ans * 10 << '\n';   dividing by 2 gives wrong answer due to approximations

    // for(auto it:edges){
    //     ans = max(ans, (dist[it[0]] + dist[it[1]] + it[2]) * 5);
    // }
    // cout<<ans<<'\n';
    int max_t = 0;
    for (int i = 0; i < m; i++)
    { // edges[i] have =[node a, node b, edge weight]
        int a = edges[i][0];
        int b = edges[i][1];
        int d = edges[i][2];
        int ans;
        if (abs(dist[a] - dist[b]) >= d) // if fire start burning from an end and edge is burned before fire starts from other end.
        // i.e. distance of b can be atmax be d from a, and if its less, edge will burn from A and reach B with d distance before it gets burned from somewhere else
        {
            ans = 10 * (min(dist[a], dist[b]) + d);
        }
        else // edge is burning from both the ends
        // A _________(t)_______B => t is instance at which buring from both ends meets (edge is completely burned now)
        // so total time taken for d length string to burn like this => d=(t-A)+(t-B) => t=(A+B+d)/2
        {
            ans = 10 * (dist[a] + dist[b] + d) / 2;
        }
        max_t = max(max_t, ans);
    }
    cout << max_t << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}