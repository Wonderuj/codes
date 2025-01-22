#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vpii vector<pii>
#define vvi vector<vi>
#define printArr(a, start, end)       \
    for (int i = start; i < end; ++i) \
        cout << a[i] << " ";
#define readArr(a, start, end)        \
    for (int i = start; i < end; ++i) \
        cin >> a[i];
#define read2D(mat, n, m)           \
    for (int i = 0; i < n; ++i)     \
        for (int j = 0; j < m; ++j) \
            cin >> mat[i][j];
#define F first
#define S second
#define B begin()
#define E end()
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define len(x) (int)x.length()
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define repn(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define repd(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define repauto(a, b) for (auto &(a) : (b))
#define int long long

const int MOD = 1e9 + 7;

vi edges[150010];
int label[150010];  // current component of each vertex
int sz[150010];     // size of the each label (component)
int nedges[150010]; // number of edges in the component

void relabel(int u, int target)
{ // relabel vertex u and neighbours with target label
    if (label[u] == target)
        return;
    label[u] = target;
    for (int x : edges[u])
        relabel(x, target);
}

void merge(int u, int v)
{
    edges[v].pb(u);
    edges[u].pb(v);

    int cu = label[u], cv = label[v]; // component of u and v
    ++nedges[cu];
    if (cu == cv)
        return; // as they are already in same component. we just increase number of edge in this component

    if (sz[cu] > sz[cv])
    { // we assume that size of u component is <= sz of comp v
        swap(u, v);
        swap(cu, cv);
    }

    relabel(u, cv); // relabelling

    sz[cv] += sz[cu];         // maintained the size
    nedges[cv] += nedges[cu]; // maintained the edges
}

void solve()
{
    int n, m;
    cin >> n >> m;

    rep(i, 0, n)
    {
        sz[i] = 1;  //every component is size 1 initially
        label[i] = i; //all nodes are marked with different component labels
    }

    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        merge(u, v);
    }

    bool possible = 1;
    rep(i, 0, n)    //checking if number of edges in component is equal to sz*sz-1/2 of component (so that every edge connects every other edge in component)
    {
        if (nedges[label[i]] != sz[label[i]] * (sz[label[i]] - 1) / 2){
            possible=0;
        }
    }
    cout<<(possible?"YES\n":"NO\n");
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}