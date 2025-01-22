#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    x=min(x,y);
    cout<<(n+x-1)/x<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
} 