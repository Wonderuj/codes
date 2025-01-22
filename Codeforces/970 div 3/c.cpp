#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int l,r;
    cin>>l>>r;
    if(l==r) {
        cout<<"1\n";
        return;
    }

    int n=r-l;
    int ans=1;
    for(int i=1;i*(i+1)<=2*n;i++){
        ans++;
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}