/*
2
4
7


A
AB
ABC
ABCD
A
AB
ABC
ABCD
ABCDE
ABCDEF
ABCDEFG
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
                cout << char('A' + j);
            else
                cout << " ";
        }
        cout << endl;
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