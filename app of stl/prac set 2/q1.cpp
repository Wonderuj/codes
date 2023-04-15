#include <bits/stdc++.h>
using namespace std;
//#define fort(i, n) for (int i = 0; i < (n); i++)
void solve()
{
    int q;
    cin >> q;
    stack<int> s;
    for (int i = 0; i <q; i++)
    {
        string t;
        cin >> t;
        if (t == "add")
        {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (t == "remove")
        {
            if (!s.empty())
            {
                s.pop();
            }
        }
        else if (t == "print" && !s.empty())
        {
            cout<<s.top()<<'\n';
        }
        else
        {
            cout << "0\n";
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