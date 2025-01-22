#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(), x.end()
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(m);
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    sort(ALL(p));
    while (q--)
    {
        int d;
        cin >> d;
        int R = p.back();
        int L = p[0];

        if (R < d)
        {
            cout << n - R;
        }
        else if (d < L)
        {
            cout << L - 1;
        }
        else
        {

            R = *upper_bound(ALL(p), d);
            auto it = lower_bound(ALL(p), d);
            it--;
            L = *it;
            cout << (R - L) / 2;
        }
        cout << endl;
    }
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