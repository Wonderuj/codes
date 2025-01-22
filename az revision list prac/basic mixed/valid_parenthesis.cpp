#include <bits/stdc++.h>
using namespace std;
string s;

void solve()
{
    cin >> s;
    stack<char> st;
    int n = s.length();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      
        // if (s[i] == '(')
        // {
        //     st.push(s[i]);
        // }
        // else if (!st.empty() && s[i] == ')' && st.top() == '(')
        // {
        //     st.pop();
        // }
        // else if (st.empty() && s[i] == ')')
        // {
        //     count++;
        // }

        if(s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(!st.empty() && s[i]==')'){
                st.pop();
            }
            else{
                count++;
            }
        }
    }
    while(!st.empty()){
        count++;
        st.pop();
    }
    cout<<count<<endl;
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