//Alternative example of paranthesis problem with more types of brackets. (STL application idea 1)
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    map<char, int> mp;
    mp['('] = 1;
    mp['['] = 2;
    mp['{'] = 3;
    mp[')'] = 4;
    mp[']'] = 5;
    mp['}'] = 6;
    string s;
    cin >> s;
    stack<int> st;
    bool isBal = 1;
    for (auto v : s)
    {
        int nums = mp[v];
        if (nums <= 3)  //Opening bracket
        {
            st.push(nums);
        }
        else //closing bracket, top element has to be nums-3
        {
            if (st.empty() || st.top() != nums - 3)
            {
                isBal = 0;
                break;
            }
            st.pop();
        }
    }
    if (!st.empty())
        isBal = 0;
    if (isBal)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}