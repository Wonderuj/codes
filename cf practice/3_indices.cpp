/*
I did lot of things but the answer was simple
for (int i = 1; i < n - 1; ++i) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            cout << "YES" << endl;
            cout << i << ' ' << i + 1 << ' ' << i + 2 << endl;
            return;
        }
    }
    cout<<"NO\n";
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n),nl(n),nr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        nl[i]=-1;
        nr[i]=-1;
    }

    stack<int>st;
    st.push(0);
    for(int i=0;i<n;i++){
        if(v[st.top()]<v[i]){
            nl[i]=st.top();
        }
        else if(v[st.top()]>=v[i]){
            st.pop();
            st.push(i);
        }
    }
    
    st.pop();   
    st.push(n-1);
    for(int i=n-1;i>=0;i--){
        if (v[st.top()] < v[i])
        {
            nr[i] = st.top();
        }
        else if (v[st.top()] >= v[i])
        {
            st.pop();
            st.push(i);
        }
    }
   
    for(int i=0;i<n;i++){
        if(nr[i]!=-1 and nl[i]!=-1){
            cout<<"YES\n";
            cout<<nl[i]+1<<" "<<i+1<<" "<<nr[i]+1<<'\n';
            return;
        }
    }
    cout<<"NO\n";
}   
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}