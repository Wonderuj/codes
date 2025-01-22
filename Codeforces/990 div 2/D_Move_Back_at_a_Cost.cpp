#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x=0;
    for(int i=0;i<n;i++){
        if(a[i]>a[i+1]){
           a.push_back(a[i]+1);
            x=i;
            break;
        }
    }

    for(int i=0;i<=n;i++){
        if(i==x) continue;
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}