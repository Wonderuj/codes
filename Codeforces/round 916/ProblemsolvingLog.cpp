#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin>>s;
    unordered_map<int,int>mp;
    for(auto x:s){
        mp[x]++;
    }
    int cnt=0;
    for(int i=0;i<26;i++){
        if(mp['A'+i]>=i+1) cnt++;
    }
    cout<<cnt<<'\n'; 
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