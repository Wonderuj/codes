#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n%2==0){
        cout<<-1<<endl;
        return;
    }
    int j=1;
    vector<int>v(n);
    for(int i=n/2;i<n;i++){
        v[i]=j;
        j++;
    }

    for(int i=(n/2)-1;i>=0;i--){
        v[i]=j;
        j++;
    }
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}