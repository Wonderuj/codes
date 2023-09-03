/*Question
Zenithland has n cities and m roads between them. Your task is to check for the existence of a round trip that begins in a city,
goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.


Input Format

The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1, 2, …, n.
Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.

Sample Input 1

5 6
1 3
1 2
5 3
1 5
2 4
4 5

Sample Output 1

YES

Sample Input 2

4 3
1 2
1 3
3 4

Sample Output 2

NO*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;
vector<int> parent;
bool is_cycle = false;
void dfs(int node, int par)
{
    parent[node] = par;
    vis[node] = 2;
    for (auto v : g[node])
    {
        if (v == parent[node])
        {
            continue;
        }
        if (vis[v] == 1)
        {
            dfs(v, node);
        }
        else if (vis[v] == 2)
        {
            is_cycle = true;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 1);
    parent.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
        {
            dfs(i, 0);
            comp++;
        }
    }
    if (is_cycle)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO\n";
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

//-------------------------------------------------------------------------------------------------------------------

// I was trying out diffrent things in my code with printing and learning how dfs is working..................
// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> g;
// vector<int> vis;
// vector<int> parent;
// vector<int> any_cycle;
// bool is_cycle = false;
// void dfs(int node, int par)
// {
//     parent[node] = par;
//     vis[node] = 2;
//     cout << "marking the node as " << node << " : " << vis[node] << endl;
//     for (auto v : g[node])
//     {
//         if (v == parent[node])
//         {
//             continue;
//         }
//         if (vis[v] == 1)
//         {
//             dfs(v, node);
//         }
//         else if (vis[v] == 2)
//         {
//             cout << "cycle found" << endl;
//             if (!is_cycle)
//             {
//                 int temp = node;
//                 while (temp != v)
//                 {
//                     any_cycle.push_back(temp);
//                     temp = parent[temp];
//                 }
//                 any_cycle.push_back(temp);
//                 reverse(any_cycle.begin(), any_cycle.end());
//             }
//             if (any_cycle.size() > 3)
//             {
//                                         //was trying to print a cycle if its only of size >3.
//                 is_cycle = true;
//             }
//             else{
//                 any_cycle.clear();
//             }
//         }
//     }
//     vis[node] = 3;
//     cout << "marking the node as " << node << " : " << vis[node] << endl;
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     g.resize(n + 1);
//     vis.assign(n + 1, 1);
//     parent.assign(n + 1, 0);
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }
//     int comp = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (vis[i] == 1)
//         {
//             dfs(i, 0);
//             comp++;
//         }
//     }
//     if (is_cycle)
//     {
//         cout << "YES" << '\n';
//         for (auto a : any_cycle)
//         {
//             cout << a << " ";
//         }
//     }
//     else
//     {
//         cout << "NO\n";
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