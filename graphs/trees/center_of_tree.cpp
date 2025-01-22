#include <bits/stdc++.h>
using namespace std;

vector<int> g[200100];
int dep[200100];
int par[200100];

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
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    } 


    //this is very important edge case, I missed this while solving question
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }

    dfs(1, 0, 0);
    int firstEnd = 1;
    for (int j = 2; j <= n; j++)
    {
        if (dep[j] > dep[firstEnd])
        {
            firstEnd = j;
        }
    }

    dfs(firstEnd, 0, 0);
    int secondEnd = 1;
    for (int j = 2; j <= n; j++)
    {
        if (dep[j] > dep[secondEnd])
        {
            secondEnd = j;
        }
    }


    int dia = dep[secondEnd];

    //if diameter is even then there will be one center
    if (dia % 2 == 0)
    {
        int center = -1;
        int i = dia/2;
        center=par[secondEnd];
        i--;
        while (i--)
        {
            center = par[center];   //travelling up using the parent array
            i++;
        }
        cout << center << '\n';
    }

    else{   //odd length of dia => 2 centers
        int center1 = -1;
        int center2;
        center1 = par[secondEnd];
        int i=dia/2;
        i--;
        while (i--)
        {
            center1 = par[center1]; // travelling up using the parent array
            i++;
        }
        center2=par[center1];
        cout<<center1<<" , "<<center2<<'\n';
    }

}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}