#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    // int a[n];
    int maxi=0;
    int mini=2000;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        // a[i]=x;
        if(x>maxi){
            maxi=x;
        }
        if(x<mini) mini=x;

    }
    if(n==1){ 
        cout<<0<<endl;
        return;
    }

    cout<<(maxi-mini)*(n-1)<<endl;
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}


