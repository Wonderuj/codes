// You are given an array of N integers and a size K. Find the maximum integer for every contiguous subarray of size K.
// Sliding Window Problem

// Method 1 -Using Multiset
//  #include <bits/stdc++.h>
//  using namespace std;

// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     int arr[100010];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     multiset<int> mt;

//     for (int i = 0; i < n; i++)
//     {
//         mt.insert(arr[i]);
//         if (i - k >= 0)
//         {
//             mt.erase(mt.find(arr[i - k]));
//         }
//         if (i >= k - 1)
//         {
//             cout << *mt.rbegin() << " ";
//         }
//     }
//     cout << endl;
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

//---------------------------------------------------------------------------------------------------
// Method -2 Using Deque

#include <bits/stdc++.h>
using namespace std;

struct monotone_deque
{
    deque<int> dq;
    void insert(int x)
    {
        while (!dq.empty() && dq.back() < x)
        {
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void remove(int x)
    {
        if (dq.front() == x)
        {
            dq.pop_front();
        }
    }
    int get_maxi()
    {
        return dq.front();
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[100100];
    monotone_deque mt;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        mt.insert(arr[i]);
        if (i - k >= 0)
        {
            mt.remove(arr[i - k]);
        }

        if (i >= k - 1)
        {
            cout << mt.get_maxi() << " ";
        }
    }
    cout<<'\n';
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