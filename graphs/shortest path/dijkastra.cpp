#include <bits/stdc++.h>
using namespace std;
using lli = long long;
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define ii pair<int, int>

vector<ii> g[100100];
bool vis[100100];
lli dis[100100];
int n, m;

void dijkstra(int sc)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18; // resetting distance before implementing dijkstra as there might be test cases in the question
        vis[i] = 0;
    }

    dis[sc] = 0; // distance of source node is 0

    priority_queue<ii> pq;
    pq.push(MP(-0, sc)); // priority queue is maintaing distance and node. (we need to sort according to distace, so it is kept first)
    // so pushing negative will place closest nodes at top of priority queue
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
            if (dis[neigh] > dis[cur.S] + wt)
            {
                dis[neigh] = dis[cur.S] + wt;   
                pq.push(MP(-dis[neigh], neigh));
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c; // nodes, edges , weights
        cin >> a >> b;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }

    dijkstra(1);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}