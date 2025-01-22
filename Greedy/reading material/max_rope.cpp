// #include <bits/stdc++.h>
// using namespace std;
// priority_queue<int> pq;

// void solve()
// {
//     int n;
//     cin >> n;
//     int ropel = 0;
//     int sum = 0;
//     int cost = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         sum += x;
//         pq.push(-x);
//     }
//     while (true)               //or while(!pq.empty){  //  }
//     {
//         int a = pq.top();
//         pq.pop();
//         a += pq.top();
//         pq.pop();
//         cost += a;
//         if (!pq.empty())
//         {
//             pq.push(a);
//         }
//         else
//         {
//             break;
//         }
//     }
//     cout << -1 * cost << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }

#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq; // this is way to directily maintain reverse priority queue.

void solve()
{
    int n;
    cin >> n;
    int ropel = 0;
    int sum = 0;
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        pq.push(x);
    }
    while (true)
    {
        int a = pq.top();
        pq.pop();
        a += pq.top();
        pq.pop();
        cost += a;
        if (!pq.empty())
        {
            pq.push(a);
        }
        else
        {
            break;
        }
    }
    cout << cost << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}