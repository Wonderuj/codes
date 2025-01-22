#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }
    string s;
    cin >> s;

    stack<pair<int, int>> st;
    vector<int> prefix(n + 1,0);

    prefix[0] = v[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = v[i] + prefix[i - 1];
    }
 
    // cout<<endl;

    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>>right;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            left.push(i);
        else
            right.push(i);
    }

    while (left.size() != right.size())
    {
        if (left.size() > right.size())
        {
            left.pop();
        }
        else
            right.pop();
    }

    int sum = 0;
    while (!left.empty() and !right.empty())
    {
        if (left.top() > (right.top()))
        {
            left.pop();
            right.pop();
        }
        else
        {
            sum += (prefix[right.top()] - ((left.top()>0)?prefix[left.top()-1]:0));
            left.pop();
            right.pop();
        }
    }

    cout <<sum << endl;
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