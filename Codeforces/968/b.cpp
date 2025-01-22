#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }

    sort(v.begin(), v.end());
    cout << v[n / 2];
    // int j=0;
    // stack<int>st;
    // st.push(v[0]);
    // for(int i=1;i<n;i++){
    //     if(j%2==0){
    //         st.top()=max(st.top(),v[i]);
    //     }
    //     else {
    //         st.top()=min(st.top(),v[i]);
    //     }
    //     j++;
    // }
    // cout<<st.top()<<endl;
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