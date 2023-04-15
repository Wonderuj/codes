#include <bits/stdc++.h>
using namespace std;

void solve()
{
    set<int> s;
    int q;
    cin >> q;
    while (q--)
    {
        string s1;
        cin >> s1;
        if (s1 == "add")
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        else if (s1 == "erase")
        {
            int x;
            cin >> x;
            if (s.count(x))
            {
                s.erase(x);
            }
        }
        else if (s1 == "find")
        {
            int x;
            cin >> x;
            auto it = s.find(x);
            if (it != s.end())
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else if (s1 == "print")
        {
            for(auto i:s){
                cout<<i<<" ";
            }
            cout<<'\n';
        }
        else{
            s.clear();
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}