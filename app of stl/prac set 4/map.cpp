#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    map<string, int> mp;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            int y;
            string x;
            cin >> x >> y;
            mp[x] = y;
        }
        else if (s == "erase")
        {
            string x;
            cin >> x;
            if (mp.find(x) != mp.end())
            {
                mp.erase(x);
            }
        }
        else
        {
            string x;
            cin >> x;
            if (mp.count(x))
            {
                cout << mp[x] << '\n';
            }
            else
            {
                cout << "0\n";
            }
        }
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