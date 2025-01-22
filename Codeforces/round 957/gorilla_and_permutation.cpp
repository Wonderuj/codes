#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>v;

    for(int i=n;i>=1;i--){
        v.push_back(i);
    }
    reverse(v.begin()+n-m,v.end());
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<'\n';
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}