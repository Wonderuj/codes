// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     vector<int> v;
//     int q;
//     cin >> q;
//     while (q--)
//     {
//         string s;
//         cin >> s;
//         if (s == "print")
//         {
//             int x;
//             cin >> x;
//             if (x < (int)v.size())
//             {
//                 cout << v[x] << "\n";
//             }
//             else if ((int)v.size() == 0)
//             {
//                 cout << "0\n";
//             }
//         }
//         else if (s == "remove")
//         {
//             if (!v.empty())
//             {
//                 v.pop_back();
//             }
//         }
//         else if (s == "add")
//         {
//             int x;
//             cin >> x;
//             v.push_back(x);
//         }

//         else if (s == "clear")
//         {
//             v.clear();
//         }
//     }
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
// this had mistake.. I didnt took care of the case when input would've been greater than size of vector for printing.

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> v;
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "print")
        {
            int x;
            cin >> x;
            if (x < (int)v.size())
            {
                cout << v[x] << "\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (s == "remove")
        {
            if (!v.empty())
            {
                v.pop_back();
            }
        }
        else if (s == "add")
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        else if (s == "clear")
        {
            v.clear();
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