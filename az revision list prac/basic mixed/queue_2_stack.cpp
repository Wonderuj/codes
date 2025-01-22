#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin>>q;
    stack<int> s1, s2;

    while (q--)
    {
        string s;
        cin>>s;
        if (s == "push")
        {
            int x;
            cin >> x;
            s1.push(x);
        }
        if (s == "pop")
        {
            if (!s2.empty())
            {
                cout << s2.top() << endl;
                s2.pop();
            }
            else
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                cout << s2.top() <<endl;
                s2.pop();
            }
        }
        if(s=="front"){
            if (!s2.empty())
            {
                cout << s2.top() << endl;
            }
            else
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                cout << s2.top() <<endl;
            }
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