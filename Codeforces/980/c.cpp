#include <bits/stdc++.h>
using namespace std;
// #define ll long long int
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
        cin >> a[I];
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
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FOREACH(a, b) for (auto &(a) : (b))
// #define int long long

const int MOD = 1e9 + 7;

bool comp(pii &a, pii &b)
{
    if (max(a.F, a.S) == max(b.F, b.S))
        return min(a.F, a.S) < min(b.F, b.S);
    return max(a.F, a.S) < max(b.F, b.S);
}

void solve()
{
    int n;
    cin >> n;
    vpii v(n);
    FOREACH(x, v)
    {
        cin >> x.first >> x.second;
    }

    sort(all(v), comp);
    FOREACH(x, v)
    {
        cout << x.F << " " << x.S << " ";
    }
    cout << endl;
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