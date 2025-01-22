#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();

    if (n == 1)
    {

        if (s[0] != 'z')
        {
            char x = s[0] + 1;
            cout << x << s[0] << '\n';
        }
        else
            cout << "az" << endl;

        return;
    }
    char x;
    string s1,s2;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            string s1, s2;
            s1 = s.substr(0, i + 1);
            s2 = s.substr(i + 1, n - (i + 1));
            // for (int j = 0; j <= i; j++)
            // {
            //     cout << s[j];
            // }

            if (s[i] != 'z')
            {
                x = s[i] + 1;
            }
            else
            {
                x = 'a';
            }
            // cout << x;
            cout << s1 << x << s2 << '\n';
            // for (int j = i + 1; j < n; j++)
            // {
            //     cout << s[j];
            // }
            // cout << '\n';
            return;
        }
    }

    if (s[0] != 'z')
    {
        char x = s[0] + 1;
        cout << x << s << '\n';
    }
    else
        cout << 'a'<<s<< endl;
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