#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]%=2;
    }
    int op=0;
    for(int i=0;i<n-1;i++){
        if(v[i]==v[i+1]) op++;
    }   
    cout<<op<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}