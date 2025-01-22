#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(j==n-i) ans++;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}