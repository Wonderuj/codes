#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    int mm = stoi(s.substr(3, 2));
    int hh = stoi(s.substr(0, 2));
    int ret = 0;
    while (hh % 10 != mm / 10 || hh / 10 != mm % 10)
    {
        mm++;
        if (mm == 60)
        {
            mm = 0;
            hh++;
        }
        if (hh == 24)
            hh = 0;
        ret++;
    }
    cout<<ret<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}