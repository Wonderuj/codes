#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int x, y;
    string s, s1, s2;
    cin >> s >> x >> y;

    s1 = "ab"; // have score of x
    s2 = "ba"; // have score of y

    if (x < y)          //we are putting the greater score in variable x and corresponding substring in s1
    {
        swap(x, y);
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    int ans=0;
    stack<char>st;
    //greedly choosing greater string to be deleted first
    //deleting all instances of s1
    for(auto &c:s){
        if(!st.empty() && c==s1[1] &&st.top()==s1[0]){
            ans+=x;
            st.pop();
        }   
        else{
            st.push(c);
        }

    }

    s="";

    while(!st.empty()){
        s+=st.top();
        st.pop();
    }
    reverse(s.begin(),s.end());

    for (auto &c : s)
    {
        if (!st.empty() && c == s2[1] && st.top() == s2[0])
        {
            ans += y;
            st.pop();
        }
        else
        {
            st.push(c);
        }
    }

    cout<<ans<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}