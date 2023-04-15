#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    sort(v.begin(), v.end());
    vector<pair<int, int>> p;
    // while(q--)
    for(int j=0;j<q;j++)
    {
        int t, x;
        cin >> t >> x;
        p.push_back(make_pair(t, x));
    }
    for (int i = 0; i < q; i++)
    {
        if (p[i].first == 1)
        {
            auto low = lower_bound(v.begin(), v.end(), p[i].second);
            auto k = (low - v.begin());
            if (k == n)
            {
                cout << "-1 ";
            }
            else
            {
                cout << v[k] << " ";
            }
        }
        else if (p[i].first == 2)
        {
            auto up = upper_bound(v.begin(), v.end(), p[i].second);
            auto k = (up - v.begin());
            if (k == n)
            {
                cout << "-1 ";
            }
            else
            {
                cout << v[k] << " ";
            }
        }
        else if (p[i].first == 4)
        {
            auto low = lower_bound(v.begin(), v.end(), p[i].second);
            auto k = (low - v.begin());
            cout << k << " ";
        }
        else
        {
            auto up = upper_bound(v.begin(), v.end(), p[i].second);
            auto k = (up - v.begin());
            cout << k << " ";
        }
    }
    cout << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    while (_t--){
        solve(); 
        }
}