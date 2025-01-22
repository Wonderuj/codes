#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int j=0;
    for(int i=1;i<=n;i++){
        cout<<i+j<<" ";
        j++;
    }
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}