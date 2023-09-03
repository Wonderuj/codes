/*
You have given a graph G with n nodes and m edges. Each edge has an integer weight associated with. 
The weight of an edge may negative, positive or zero. If the graph contains a cycle with total weight > 0, print -1. 
Otherwise, find the weight of the highest weighted path from node 1 to n.


Input Format

The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1, 2, …, n.
Then, there are m lines describing the edges. Each line has three integers a, b and x: 
the edge starts at node a, ends at node b, and weight of the edge is x. All edges are unidirectional edges.
You can assume that it is possible to get from node 1 to node n.


Output Format

Print the answer on a new line.


Constraints

1 ≤ 2500 ≤ n
1 ≤ 5000 ≤ m
1 ≤ a, b ≤ n
−109 ≤ x ≤ 109
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dist;
int flag = 0;

void relax()
{
    for (int node = 1; node <= n; node++)
    {
        for (auto v : g[node])
        {
            int neigh = v.first;
            int wt = v.second;

            if (dist[neigh] > dist[node] + wt)
            {
                flag = 1;
                dist[neigh] = dist[node] + wt;
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    dist.assign(n + 1, 1e18);
    
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, -c});
    }
    dist[1] = 0;

    for (int i = 1; i < n; i++)       //relaxing the edge |v|-1 times
    {
        relax();
    }
    flag = 0;

    relax();
    if (flag)
    {
        cout << -1 << "\n";
        return;
    }

    cout << -dist[n] << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}

/*
Construct a new graph with weights multiplies by -1.
Now check for the existence of a negative cycle in this graph.
If it does not exist, find the shortest distance from 1 to n.
Note that since weights can be negative, use Bellman-Ford Algorithm.


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mod = 1e9 + 7;

const int N = 100010;

struct edge {
    int u, v, w;
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    edge E[m];
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        E[i].u = a;
        E[i].v = b;
        E[i].w = -c;
    }

    ll dist[n + 1];
    for(int i = 1; i <= n; i++) {
        dist[i] = 1e18;
    }
    dist[1] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            int u = E[j].u;
            int v = E[j].v;
            int w = E[j].w;
            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    bool neg = false;
    for(int i = 0; i < m; i++) {
        int u = E[i].u;
        int v = E[i].v;
        int w = E[i].w;
        if(dist[v] > dist[u] + w) {
            neg = true;
            break;
        }
    }

    if(neg) cout << "-1\n";
    else {
        assert(dist[n] != 1e18);
        cout << -dist[n] << "\n";
    }
}

------------------------------------------------------------------------------------------


#include<bits/stdc++.h>
#define int long long
using namespace std;
using ii = pair<int, int>;

int n, m;

vector< pair< ii, int > > edgelist;
int dist[2505];

signed main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edgelist.push_back({{a,b},-c});
    }

    for(int i=1;i<=n;i++){
        dist[i] = 1e18;
    }
    dist[1] = 0;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            int u = edgelist[j].first.first;
            int v = edgelist[j].first.second;
            int w = edgelist[j].second;
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    for(int j=0;j<m;j++){
        int u = edgelist[j].first.first;
        int v = edgelist[j].first.second;
        int w = edgelist[j].second;
        if(dist[v] > dist[u] + w){
            cout<<"-1\n";
            return 0;
        }
    }

    cout<<-dist[n]<<"\n";
}
*/