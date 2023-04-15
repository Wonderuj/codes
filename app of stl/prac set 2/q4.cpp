#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int q;
    cin >> q;
    queue<int> k;
    for(int i=0; i<q ; i++)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            int x;
            cin >> x;
            k.push(x);
        }
        else if (s == "remove" )
        {
            if (!k.empty())
                k.pop();
        }
        else
        {
            if (!k.empty())
            {
                cout << k.front()<<'\n';
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