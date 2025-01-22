#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    long long arr[n+1];
    arr[0]=0;
    for(int i=1;i<=n;i++) cin>>arr[i];

    for(int i=2;i<=n;i++){
        arr[i]+=arr[i-1];
    }

    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        long long sum= arr[n]-(arr[r]-arr[l-1])+(r-l+1)*k;
        cout<<((sum%2)?"YES":"NO")<<endl;
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}