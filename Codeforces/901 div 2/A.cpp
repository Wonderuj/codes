#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int a,b,n;
    cin>>a>>b>>n;
    int ans=b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ans+=min(a-1,x);
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}