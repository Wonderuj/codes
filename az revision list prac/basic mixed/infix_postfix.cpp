/*
You are given an expression of the form A op B, where an operator is in-between every pair of operands. 
This form of expression is also called Infix expression.  You have to convert it to an expression of the form A B op,
 where an operator is followed for every pair of operands. This form of expression is also called Postfix expression. 
 The operators can be: ^, -, +, *, /. The priority of operators is as follows '+', '-', '*', '/', '^' (increasing left to right)
'^' is for exponentiation. The operands are lowercase English alphabets.

To read more about Infix and Postfix expression, you can refer to this link. (www.cs.man.ac.uk › ~pjj › fix)

Your task is to convert Infix expression to Postfix expression.*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    string str = "";
    stack<char> st;
    map<char, int> mp;
    mp['+'] = 0;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 3;
    mp['^'] = 4;
    mp['('] = 5;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            str += s[i];
        }

        else
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {

                if (s[i] == ')')
                {
                    while (st.top() != '(')
                    {
                        str += st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else
                {
                    if (mp[s[i]] >= mp[st.top()])
                    {
                        st.push(s[i]);
                    }
                    else // a*(b^c+d)-e  --Test Case
                    {
                        //while (st.top() != '(' && (mp[st.top()] > mp[s[i]]) && !st.empty())
                       // while (st.top() != '(' && ((mp[st.top()] > mp[s[i]]) && !st.empty()))
                        while (!st.empty() && st.top() != '(' && (mp[st.top()] > mp[s[i]]))
                        {
                            str += st.top();
                            st.pop();
                        }
                        st.push(s[i]);
                    }
                }
            }
        }
    }
    while (!st.empty())
    {
        str += st.top();
        st.pop();
    }
    cout << str << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    string d;
    getline(cin, d);
    while (_t--)
        solve();
}
