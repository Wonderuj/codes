#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(),greater<int>());
    int k=0;
    int maxi=0;
    for(int i=0;i<n-1;i++){
        k+=v[i];
        if(k<=m){
            maxi=max(maxi,k);
        }
        if(v[i]-v[i-1]>1){
            k=0;
        }
    }
    cout<<maxi<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}