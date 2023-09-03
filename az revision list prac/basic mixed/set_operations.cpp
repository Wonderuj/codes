/*QUestion
You are given two sets, A and B of N and M integers respectively. There are no duplicate integers in each respective array.
Find the set union, set intersection and set difference (A-B) of the two sets in sorted order.*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    int arr[10010];
    int brr[10010];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]] += 1;       //We assume set A gives weightage of +1
    }
    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
        mp[brr[i]] += 2;        //We assume set B gives weightage of +2
    }

    for (auto v : mp)
    {
        cout << v.first << " ";           //UNION - All the elements in the Map
    }
    cout << '\n';

    for (auto v : mp)
    {
        if (v.second == 3)
        {
            cout << v.first << " ";         //Intersection - elements which had came in set A and also in set B giving +1+2 =+3 
        }
    }
    cout << '\n';

    for (auto v : mp)
    {
        if (v.second == 1)
        {
            cout << v.first << " ";         //A-B difference  - Elements which are only present in A that is remained +1 after all elements are inserted
        }
    }
    cout << '\n';
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

//other way - Copied 
// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> v1(n), v2(m);
//     for (auto &i : v1)
//         cin >> i;
//     for (auto &i : v2)
//         cin >> i;
//     sort(v1.begin(), v1.end());
//     sort(v2.begin(), v2.end());
//     vector<int> uni(v2);
//     vector<int> inter;
//     set<int> diff(v1.begin(), v1.end());
//     for (auto i : v1)
//     {
//         if (!binary_search(v2.begin(), v2.end(), i))
//         {
//             uni.push_back(i);
//         }
//         else
//         {
//             inter.push_back(i);
//             diff.erase(i);
//         }
//     }
//     sort(uni.begin(), uni.end());
//     for (auto i : uni)
//         cout << i << " ";
//     cout << '\n';
//     for (auto i : inter)
//         cout << i << " ";
//     cout << '\n';
//     for (auto i : diff)
//         cout << i << " ";
//     cout << '\n';
// }

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int _t;
//     cin >> _t;
//     string d;
//     getline(cin, d);
//     while (_t--)
//         solve();
// }