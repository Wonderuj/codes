#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int s, n;
    cin >> s >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        if (v[i].first >= s)
        {
            cout << "NO\n";
            return;
        }

        else
            s += v[i].second;
    }
    cout << "YES\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}