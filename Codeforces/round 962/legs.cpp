#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
   
    int ans=0;
    while(n>0){
        if(n/4==0){
            n -= 2;
            ans++;
        }
        else {
            n-=4;
            ans++;
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