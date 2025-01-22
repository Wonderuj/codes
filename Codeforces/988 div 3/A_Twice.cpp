#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    map<int,int>mp;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    int ans=0;
    for(auto &[x,k]:mp){
        ans+=k/2;
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}