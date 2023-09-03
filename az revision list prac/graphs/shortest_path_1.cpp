/*Question
There are n cities and m roads. The capital is located at 1. Your task is to determine the length of the shortest route from the capital to every city.


Input Format

The first input line has two integers n and m: the number of cities and road connections. The cities are numbered 1, 2, …, n, and city 1 is Capital.
After that, there are m lines describing the roads. Each line has three integers a, b and c: 
A road begins at city a, ends at city b, and its length is c. Each road is a one-way road.
You can assume that it is possible to travel from Capital to all other cities.
*/

#include <bits/stdc++.h>
using namespace std;
using lli = long long;
// #define int long long
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define ii pair<int, int>

int n, m;
vector<vector<ii>> g;
vector<bool> vis;
vector<lli> dist;

void dijkastra(int sc)
{
    for(int i=1;i<=n;i++){
        vis[i]=0;
        dist[i]=1e18;
    }
    priority_queue<ii> pq;
    dist[sc] = 0;
    pq.push(MP(-0, sc));
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
                pq.push(MP(-dist[neigh], neigh));
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    // vis.assign(n + 1, 0);
    // dist.assign(n + 1, 1e18);
    vis.resize(n + 1);
    dist.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
        // g[b].pb({a,c});  one way road is given
    }

    dijkastra(1);
    for (int i=1;i<=n;i++)
    {
        cout << dist[i] << " ";
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