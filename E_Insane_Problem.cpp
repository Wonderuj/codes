#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int MAX = 1e9 + 5;
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    vector<int> precomp;

    int n = k;
    while (n < MAX)
    {
        precomp.push_back(n);
        n *= n;
    }

    int ans = 0;
    for (int x = l1; x <= r1; x++)
    {
        for (auto z : precomp)
        {
            if (x * z >= l2 and x * z <= r2)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
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