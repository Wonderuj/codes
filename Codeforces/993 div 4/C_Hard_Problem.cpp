#include<bits/stdc++.h>
using namespace std;

void solve(){
    int m,a,b,c;
    cin>>m>>a>>b>>c;
    
    int ans= min(a,m)+min(b,m)+min((2*m-((min(a,m))+min(b,m))),c);
    

    cout<<ans<<endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}