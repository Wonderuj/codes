// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;

//     string t = s;
//     reverse(t.begin(), t.end());
//     cout << min(s, t + s) << "\n";
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int _t;
//     cin >> _t;
//     while (_t--)
//         solve();
// }

#include <bits/stdc++.h>
using namespace std;

void solve()
{

    string s;
    cin >> s;
    int n = s.length();
    string str;
    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == 'W')

        {
            if (s.substr(i, 3) == "WUB")
            {
                if (i == 0 or i == n - 3)
                {
                    i += 3;
                    continue;
                }
            }
            else
                str.push_back(' ');
        }

        else
        {
            str.push_back(s[i]);
        }
        if (i == n - 3 and s.substr(i, 3) != "WUB")
        {
            str+=s.substr(i, 3);
        }
    }
    cout<<str<<'\n';
}

cout << str << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}