#include <bits/stdc++.h>
using namespace std;

string determine(char ch)
{
    if (ch == '(')
    {
        return "ob";
    }
    else if (ch == ')')
    {
        return "cb";
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        return "operand";
    }
    else
    {
        return "operator";
    }
}
void solve()
{
    //char ch;
    stack<char> s1;
    map<char, int> mp;
    mp['+'] = 1;
    mp['-'] = 2;
    mp['*'] = 3;
    mp['/'] = 4;
    mp['^'] = 5;

    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (determine(s[i]) == "operand")
        {
            cout << s[i];
        }
        else if (determine(s[i]) == "ob")
        {
            s1.push(s[i]);
        }
        else if (determine(s[i]) == "cb")
        {
            while (s1.top() != '(')
            {
                //ch=s1.top();
                //cout << ch ;
                cout<<s1.top();
                s1.pop();
            }
            s1.pop(); // popping the opening bracket
        }
        else
        { // operator
            if (!s1.empty())
            {
                if (s1.top() == '(' || mp[s[i]] >= mp[s1.top()])
                {
                    s1.push(s[i]);
                }

                else
                {
                    while (!s1.empty() && s1.top() != '(' && mp[s1.top()] >= mp[s[i]])
                    {
                        cout << s1.top();
                        s1.pop();
                    }
                    s1.push(s[i]);
                }
            }
            else
            {
                s1.push(s[i]);
            }
        }
    }
    while (!s1.empty())
    {
        //ch=s1.top();
        cout << s1.top();
        s1.pop();
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