#include <bits/stdc++.h>
using namespace std;
#define int long long
bool comp(int &a, int &b)
{
    return (b < a);
}
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n),w(n);
    // for (int k = 0; k < n; k++)
    // {
    //     int x; cin>>x;
    //     v.push_back(x);
    // }
    for(auto &i:v){
        cin>>i;
    }
    for (auto &i : w)
    {
        cin >> i;
    }

    // for (int k = 0; k < n; k++)
    // {
    //     int x;
    //     cin >> x;
    //     w.push_back(x);
    // }

    // minimise the dot

    sort(v.begin(), v.end(),comp);
    sort(w.begin(),w.end());
    int sum=0;
    for(int k=0; k<n;k++){
        sum+=(v[k]*w[k]);
    }
    cout<<sum<<'\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}