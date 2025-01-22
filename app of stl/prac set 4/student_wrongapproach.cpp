// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> a(n);
//     vector<int> b(m);
//     // int arr1[n],arr2[m];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr1[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     a.insert(arr1[i]);
    // }
//     // for (int i = 0; i < m; i++)
//     // {
//     //     cin >> arr2[i];
//     // }
//     // for (int i = 0; i < m; i++)
//     // {
//     //     b.insert(arr2[i]);
//     // }
//     // for (int i = 0; i < n; i++)
//     // {
//     //     int x;
//     //     cin >> x;
//     //     a.insert(x);
//     // }
//     // for (int i = 0; i < m; i++)
//     // {
//     //     int x;
//     //     cin >> x;
//     //     b.insert(x);
//     // }
//     multiset<int>::iterator it;
//     // for (it = b.begin(); it != b.end(); ++it)
//     //     cout<< *it << ' ';
//     // cout << '\n';
//     for (it = b.begin(); it != b.end(); it++)
//     {
//         // auto p = a.find(*it);
//         //int c=a.count(*it);
//         // if (p != a.end())
//         // {
//         //     cout << "YES\n";            
//         // }
//         // else
//         // {
//         //     cout << "NO\n";
//         //     a.insert(*it);
//         // }
//         if (!a.count(*it))
//         {
//             cout << "NO\n";
//             a.insert(*it);
//         }
//         else
//         {
//             cout << "YES\n";
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
