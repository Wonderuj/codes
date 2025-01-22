#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,b;
    cin>>n>>b;
    if(n>=b) {cout<<n<<endl; return;}

    int temp=b-n;
    if(n-(b-n)<=0) cout<<0<<endl;
    else cout<<n-(b-n)<<endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}