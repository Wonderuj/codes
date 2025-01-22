#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            if(i+j>=n-1 and i>=j-(n-1)){
                cout<<"*";
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}