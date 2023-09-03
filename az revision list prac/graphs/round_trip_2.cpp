//DFS
// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> g;
// vector<int> vis;
// int ans;

// void dfs(int node)
// {
//     vis[node] = 1;
//     for (auto v : g[node])
//     {
//         if (vis[v] == 0)
//         {
//             dfs(v);
//         }
//         else if (vis[v] == 1)
//         {
//             ans = true;
//         }
//         else if (vis[v] == 2)
//         {
//             // cross edge
//         }
//     }
//     vis[node] = 2;
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     g.clear();
//     g.resize(n + 1);
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//     }
//     vis.clear();
//     vis.assign(n + 1, 0);
//     ans = false;
//     for (int i = 1; i <= n; i++)
//     {
//         if (vis[i] == 0)
//         {
//             dfs(i);
//         }
//     }
//     if (ans)
//     {
//         cout << "Yes" << endl;
//     }
//     else
//     {
//         cout << "No" << endl;
//     }
// }

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int t;
//     cin >> t;
//     while (t--)
//         solve();
// }

// BFS
// BFS

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;
void kahn()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for (auto v : g[cur])
        {
            indeg[v]--;
            if (indeg[v] == 0)
            {
                q.push(v);
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    indeg.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }
    kahn();

    // if(topo.size()!=n){
    //     cout<<"Yes\n";
    // }
    // else{
    //     cout<<"No\n";
    // }

    string s = (topo.size() != n) ? "Yes" : "No";
    cout << s << '\n';
    topo.clear();
    g.clear();         //in case of test cases, always clear the graph and vectors. VVVI , I forgot this earlier
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
Description
Zenithland has n  cities and m  flight connections. 
Your task is to design a round trip that begins in a city, goes through one or more other cities, and finally returns to the starting city. 
Every intermediate city on the route has to be distinct. 

Input Format

First line contains T  - Number of test cases. 
First input line of each test case has two integers n  and m : the number of cities and flights. 
The cities are numbered 1 , 2 , … , n . Then, for each test case, there are m  lines describing the flights. 
Each line has two integers a  and b : there is a flight connection from city a  to city b . 
All connections are one-way flights from a city to another city.


Output Format

For each test case, Print "Yes" if such round trip exists, otherwise print "No" in a new line.


Constraints
1 ≤ T ≤ 10

1 ≤ n ≤ 10 5

1 ≤ m ≤ 2 ⋅ 10^5

1 ≤ a , b ≤ n

Sample Input 1

1
4 5
1 3
2 1
2 4
3 2
3 4

Sample Output 1

Yes
*/