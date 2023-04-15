// // Maximum element of subarray -> Sliding window method
//https://www.youtube.com/watch?v=l_CFMVPKv2Q

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    vector<int> v(n), ans;
    for (auto &i : v)
    {
        cin >> i;
    }
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && dq.back() < v[i])
        {
            dq.pop_back();
        }
        dq.push_back(v[i]);
    }
    ans.push_back(dq.front());
    for (int i = k; i < (int)v.size(); i++)
    {
        if (dq.front() == v[i - k])
        {   
            dq.pop_front();
        }
        while (!dq.empty() && dq.back() < v[i])
        {
            dq.pop_back();
        }
        dq.push_back(v[i]);
        ans.push_back(dq.front());
    }
    for (auto i : ans)
    {
        cout << i << " ";
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