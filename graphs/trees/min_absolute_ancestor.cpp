#include <bits/stdc++.h>
using namespace std;

int ans[100100];
int val[100100];
vector<int>g[100100];
multiset<int> mt;
void insert(int x)
{
    mt.insert(x);
}
void remove(int x)
{
    mt.erase(mt.find(x));
}
int query(int x)
{
    int ans = 1e9;
    auto it = mt.lower_bound(x);
    if (it != mt.end())
    {
        ans = min(ans, abs(*it - x));
    }
    if (it != mt.begin())
    {
        it--;
        ans = min(ans, abs(*it - x));
    }
    return ans;
}

void dfs(int node, int par)
{
    ans[node] = query(val[node]);
    insert(val[node]);
    for (auto v : g[node])
    {
        if (v != par)
        {
            dfs(v, node);
        }
    }
    remove(val[node]);
}

void solve()
{
    dfs(1, 0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}