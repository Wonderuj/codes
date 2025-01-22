#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &x:v) cin>>x;
    if(n==1 ||n==2) {
        cout<<-1<<endl;
        return;
    }
    sort(v.begin(),v.end());

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }

    int ans =(2*n*v[n/2])-sum;
    if(ans<0){
        cout<<0<<endl;
        return;
    }
    
    else cout<<ans+1<<endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}