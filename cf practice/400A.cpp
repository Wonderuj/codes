#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<string> s(2);
    cin >> s[0] >> s[1];
    int n;
    cin >> n;
    vector<pair<string, string>> st;
    st.push_back({s[0], s[1]});
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        st.push_back({s1, s2});
    }

    //killed Replaced

    for(int i=1;i<=n;i++){
        st[i].first=(st[i].first==st[i-1].first)?st[i-1].second:st[i-1].first;
    }
    for(auto x:st){
        cout<<x.first<<" "<<x.second<<endl;
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
