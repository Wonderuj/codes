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

void solve()
{
    int n, m;
    cin >> n >> m;
    vvi v;
    rep(i, 0, n)
    {
        vi temp;
        rep(i, 0, m)
        {
            int x;
            cin >> x;
            temp.pb(x);
        }
        sort(all(temp));
        v.pb(temp);
    }

    vpii temp;
    rep(i, 0, n)
    {
        int mini = *min_element(all(v[i]));
        temp.pb({mini, i});
    }
    sort(all(temp));

    int top = -1;
    int cow = 0, card = 0;
    bool flag = true;
    int it = 0;
    while (it < n * m and card < m)
    {
        int curIdx = temp[cow].S;
        int curCard = v[curIdx][card];
        // cout << "top " << top << " curcard " << curCard << endl;
        if (top < curCard)
        {
            top = curCard;
            cow++;
        }
        else
        {
            flag = false;
            break;
        }
        if (cow == n)
        {
            cow = 0;
            card++;
        }

        it++;
    }
    if (flag)
    {
        for (auto x : temp)
            cout << x.S + 1 << " ";
    }
    else
        cout << "-1";
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