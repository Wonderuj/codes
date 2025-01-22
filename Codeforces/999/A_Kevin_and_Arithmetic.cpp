#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int odd=0, even=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        odd+=(x%2==1);
        even+=(x%2==0);
    }
    if(even==0){
        ans=odd-1;
    }
    else{
        ans=odd+1;
    }
    cout<<ans<<endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}