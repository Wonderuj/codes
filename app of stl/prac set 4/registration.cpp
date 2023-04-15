#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (!m.count(s))
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << s << m[s] << endl;
        }
        m[s]++;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;
//     map<string, int> m;
//     string s;
//     while (n--)
//     {
//         cin >> s;
//         if (m.find(s) != m.end())
//         {
//             auto it = m.find(s);
//             it->second++;
//             cout << it->first << it->second << "\n";
//         }
//         else
//         {
//             m.insert(pair<string, int>(s, 0));
//             cout << "OK\n";
//         }
//     }
// }

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
// }