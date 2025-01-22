#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(auto &x:v){
        cin>>x;
    }

    int ans=0;
    int robin=0;
    for(int i=0;i<n;i++){
        if(v[i]==0){
            if(robin){
                robin--;
                ans++;
            }
        }
        if(v[i]>=k) robin+=v[i];
    }

    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}