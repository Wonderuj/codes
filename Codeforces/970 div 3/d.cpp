// #include <bits/stdc++.h>
// using namespace std;

// void dfs(int node, vector<int> &p, string &s, vector<int> &vis, vector<int> &comp, int &blacks)
// {
//     vis[node] = 1;
//     comp.push_back(node);
//     if (s[node] == '0')
//     {
//         blacks++;
//     }

//     if (!vis[p[node]])
//     {
//         dfs(p[node], p, s, vis, comp, blacks);
//     }
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> p(n + 1);
//     for (int i = 1; i <= n; ++i)
//     {
//         cin >> p[i];
//     }
//     string s;
//     cin >> s;
//     s = " " + s;

//     vector<int> vis(n + 1, 0);
//     vector<int> F(n + 1, 0);

//     for (int i = 1; i <= n; ++i)
//     {
//         if (!vis[i])
//         {
//             vector<int> comp;
//             int blacks = 0;
//             dfs(i, p, s, vis, comp, blacks);
//             for (int node : comp)
//             {
//                 F[node] = blacks;
//             }
//         }
//     }

//     for (int i = 1; i <= n; ++i)
//     {
//         cout << F[i] << " ";
//     }
//     cout << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int _t;
//     cin >> _t;
//     while (_t--)
//         solve();
// }

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        g[i] = x;
    }

    string s;
    cin >> s;
    vector<bool> vis(n + 1, false);
    vector<int> f(n + 1);

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        vector<int> cycle;
        int x = i;
        while (!vis[x])
        {
            cycle.push_back(x);
            vis[x] = true;
            x = g[x];
        }

        int cnt = 0;
        for (auto &u : cycle)
        {
            cnt += (s[u-1] == '0');
        }

        for (auto &u : cycle)
        {
            f[u] = cnt;
        }
    }

    for (int i=1;i<=n;i++)
    {
        cout << f[i]<< " ";
    }
    cout<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}