#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 1 << 26;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if ((a & 1 << (c - 'a')) == 0)
        { // first occurance
            ans += n - i;  //number of strings that can be formed with this char fixed, using operation erase op 2.
            a |= 1 << (c - 'a');
        }
    }
    cout << ans << '\n';
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