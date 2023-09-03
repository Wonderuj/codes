#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    string str;
    cin >> n;
    while (n != 0)
    {
        int rem = n % 26;
        char a = 'A' + rem-1;
        str.push_back(a);

        n /= 26;
    }
    reverse(str.begin(), str.end());
    cout << str << '\n';
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
