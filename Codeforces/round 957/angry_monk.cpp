#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>v;
    int idx=0;
    int maxi=-1;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        v.push_back(x);
        if (x>maxi){
            maxi=x;
            idx=i;
        }
    }

    int ans=0;
   
    for(int i=0;i<k;i++){
        if(i!=idx){
            ans+=v[i]+v[i]-1;
        }
    }
    cout<<ans<<'\n';

}   
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}