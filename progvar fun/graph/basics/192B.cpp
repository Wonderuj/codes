#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<bool> v(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a] = true;
        v[b] = true;
    }

    int cool = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == false)
        {
            cool = i;
            break;
        }
    }

    cout << n - 1 << endl;
    for (int i = 1; i <= n; i++)
    {
        if (i == cool)
            continue;
        cout << cool << " " << i << endl;
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