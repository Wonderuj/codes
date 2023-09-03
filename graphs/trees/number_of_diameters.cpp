#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> g[200200];
int par[200200];
int dep[200200];
int maxEnd;
int cnt = 0;
int height;
int dia;
int n;

void dfs(int node, int parent, int depth)
{
    par[node] = parent;
    dep[node] = depth;

    if (depth == height)
    {
        cnt++;
    }

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
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (n == 1 || n == 2)
    {
        cout << 1 << '\n';
        return;
    }

    dfs(1, 0, 0);
    maxEnd = 1;
    for (int j = 2; j <= n; j++)
    {
        if (dep[j] > dep[maxEnd])
        {
            maxEnd = j;
        }
    }
    // cout<<"first end: "<<maxEnd<<endl;
    dfs(maxEnd, 0, 0);
    maxEnd = 1;
    for (int j = 2; j <= n; j++)
    {
        if (dep[j] > dep[maxEnd])
        {
            maxEnd = j;
        }
    }
    // cout << "second end: " << maxEnd << endl;
    dia = dep[maxEnd];

    // cout<<"dia: "<< dia <<endl;

    if (dia % 2==0)
    {
        int k = dia / 2;
        int mid = par[maxEnd];
        k--;
        while (k--)
        {
            mid = par[mid];
        }
    // cout<<"mid: "<<mid<<endl;
        vector<int> temp;

        height = dia / 2 - 1;
        for (auto neigh : g[mid])
        {
            cnt = 0;
            dfs(neigh, mid, 0);
            temp.push_back(cnt);
        }
        int ans = 0;
        int sum = 0;
        for (auto v : temp)
        {
            ans += sum * v;
            sum += v;
        }
        cout << ans << '\n';
    }

    else
    {
        int k = dia / 2;
        int c1 = par[maxEnd];
        k--;
        while (k--)
        {
            c1 = par[c1];
        }
        int c2 = par[c1];
        vector<int> temp;

        height = dia / 2;
        cnt = 0;
        dfs(c1, c2, 0);
        temp.push_back(cnt);

        cnt = 0;
        dfs(c2, c1, 0);
        temp.push_back(cnt);
        int ans = temp[0] * temp[1];
        cout << ans << '\n';
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

/*
6
1 2
2 3
1 4
4 5
4 6
*/