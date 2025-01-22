#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    set<int> a; 
    vector<int>v(n);
    vector<int> b(m);
    for (auto &i:v)
    {
        cin >> i;
    }
    for (auto i:v)
    {
        a.insert(i);
    }
    for (auto &i : b)
    {
        cin >> i;
    }
    for (auto i : b)
    {
        auto c = a.find(i);
        if (c != a.end())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
            a.insert(i);
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



// I CAN ALSO WRITE IT LIKE THIS :
// #include <bits/stdc++.h>
//     using namespace std;
// #define int long long
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m;
//         cin >> n >> m;
//         vector<int> st1, st2;
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin >> x;
//             st1.push_back(x);
//         }
//         for (int i = 0; i < m; i++)
//         {
//             int y;
//             cin >> y;
//             st2.push_back(y);
//         }
//         set<int> s(st1.begin(), st1.end());
//         for (auto it : st2)
//         {
//             if (s.count(it))
//             {
//                 cout << "YES" << '\n';
//             }
//             else
//             {
//                 cout << "NO" << '\n';
//                 s.insert(it);
//             }
//         }
//     }

//     return 0;
// }


// First I used this approach, it was correct but the time limit exceeded. It was because vector count function was O(n) and 
// it have to go through complete vector agian and again, so I needed an optimized solution hence used set as the basic approach.
// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> a(n);
//     vector<int> b(m);
//     for (auto &i : a)
//     {
//         cin >> i;
//     }
//     for (auto &i : b)
//     {
//         cin >> i;
//     }
//     for (auto i : b)
//     {
//         auto c = count(a.begin(), a.end(), i);
//         if (c > 0)
//         {
//             cout << "YES\n";
//         }
//         else
//         {
//             cout << "NO\n";
//             a.push_back(i);
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