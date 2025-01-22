#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define B begin()
#define E end()
#define lb lower_bound
#define ub upper_bound

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    multiset<int> a, b;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.insert(x);
        sum += x;
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.insert(x);
    }

    // a min-> a.front(), max=a.back() =(*prev(a.end()))
    // b min->a.front(), max=a.back()
    int ret[3];
    for (int i = 1; i <= 2; i++)
    {
        if (i % 2)
        {
            int u = *a.B, v = *prev(b.E);
            if (u <= v)
            {
                a.erase(a.lb(u));
                b.erase(b.lb(v));
                a.insert(v);
                b.insert(u);
                sum += v - u;

            }
        }
        else
        {
            int u = *b.B, v = *prev(a.E);
            if (u <= v)
            {
                b.erase(b.lb(u));
                a.erase(a.lb(v));
                b.insert(v);
                a.insert(u);
                sum += u - v;
            }
        }
        ret[i] = sum;
    }

    if (k % 2)
    {
        cout << ret[1] << endl;
    }
    else
    {
        cout << ret[2] << endl;
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