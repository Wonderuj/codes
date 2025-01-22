#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>maxi and i%2==0){
            maxi=arr[i];
        } 
    }
    cout<<maxi<<'\n';
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}