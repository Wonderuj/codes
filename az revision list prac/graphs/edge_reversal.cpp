
/*Question
Given a directed graph with N vertices and M edges.
What is the minimum number of edges needed to reverse in order to have at least one path from vertex 1 to vertex N, 
where the vertices are numbered from 1 to N ?

Input Format
The first line containsT - the number of test cases.
The first line of each test case contains two space-separated integers N and M,
denoting the number of vertices and the number of edges in the graph respectively.
The ith line of the next M lines of each test case contains two space-separated integers Xi and Yi, 
denoting that theith edge connects vertices fromXi to Yi.

Output FormatFor each test case, 
In a single line, print the minimum number of edges we need to revert. 
If there is no way of having at least one path from 1 to N, print -1.*/

#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
int n, m;
vector<vector<ii>> g;
vector<int> dis;

void bfs(int sc)
{
    dis[sc] = 0;
    deque<int> dq;
    dq.push_front(sc);
    while (!dq.empty())
    {
        int cur = dq.front();
        dq.pop_front();
        for (auto v : g[cur])
        {
            int neigh = v.first;
            int cost = v.second;

            if (dis[neigh] > dis[cur] + cost)
            {
                dis[neigh] = dis[cur] + cost;
                if (cost == 0)
                {
                    dq.push_front(neigh);
                }
                else
                {
                    dq.push_back(neigh);
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    dis.assign(n + 1, 1e9);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            continue; // self loops
        }
        
        
        g[a].push_back({b, 0});
        g[b].push_back({a, 1});
        
    }

    bfs(1);

    if (dis[n] == 1e9)
    {
        cout << -1;
    }
    else
    {
        cout << dis[n];
    }
    cout << '\n';

    dis.clear();
    g.clear();
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    while (_t--)
        solve();
}

/*
Add a reverse edge of each original edge in the graph. Give reverse edge a weight=1 and all original edges a weight of 0. 
Now, the length of the shortest path will give us the answer.

How?

If the shortest path length is k : it means we used k reverse edges in the shortest path. So, it will give us the answer.
The shortest path algorithm will always try to use as few reverse paths as possible because they have a higher weight than the original edges.

To find the shortest path, we can use Dijkstra’s Algorithm which works in O(|E|log|V|) if implemented using adjacency lists and priority queue.
Also, since there are only 0 and 1 weight edges, we can also do this by 0 / 1  BFS in O ( N + M ) : 
maintain a deque instead of a queue and add a vertex to the front of the deque if 0 edges are used and to the back of the deque otherwise.

Note: Intended time complexity for this problem is O ( N + M )  per test case.*/