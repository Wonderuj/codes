#include <bits/stdc++.h>
using namespace std;
void solve()
{
    map<char, int> mp;
    mp['('] = 1;
    mp[')'] = 2;
    mp['_'] = 3;

    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<pair<char, int>> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (st.empty())
            {
                // cout << "insert at i: " << i << endl;
                st.push({'(', i});
            }
            else
            {
                if (mp[st.top().first] == 1)
                {
                    // cout << "insert at i: " << i << endl;
                    int x = st.top().second;
                    st.pop();
                    ans += (i - x);
                }
            }
        }

        else
        {
            if (st.empty())
            {
                st.push({s[i], i});
            }
            else
            {
                if (mp[st.top().first] - mp[s[i]] == 0)
                { // both are same
                    // cout<<"insert at i: "<<i<<endl;
                    st.push({s[i], i});
                }
                else
                {
                    // cout << "pop at i: " << i << endl;
                    int x = st.top().second;
                    st.pop();
                    ans += (i - x);
                }
            }
        }
        
    }
    cout << ans << '\n';
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