#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;

    for(int i=a;i<=1000000;i++){
        if((i%a) == (i%b)){
            cout<<i<<endl;
            return;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}