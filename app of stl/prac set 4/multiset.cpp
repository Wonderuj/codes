#include <bits/stdc++.h>
using namespace std;

void solve()
{
    multiset<int> ms;
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            int x;
            cin >> x;
            ms.insert(x);
        }
        else if (s == "erase")
        {
            int x;
            cin >> x;
            if(ms.find(x)!=ms.end())
                ms.erase(ms.find(x));
        }
        else if (s == "eraseall")
        {
            int x;
            cin >> x;
            if (ms.find(x) != ms.end()) 
                ms.erase(x);
        }
        if (s == "find")
        {
            int x;
            cin >> x;
            if (ms.count(x) > 0)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        if (s == "count")
        {
            int x;
            cin >> x;
            cout << ms.count(x) << '\n';
        }
        if (s == "print")
        {
            for (auto i : ms)
            {
                cout << i << ' ';
            }
            cout << '\n';
        }
        if (s == "empty")
        {
            ms.clear();
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

//mt.erase (2) will delete all occourances of 2 in map, whereas mt.erase(mt.find(2)) will erase first occourance.