#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int avg=(arr[0]+arr[1])/2;


    for(int i=2;i<n;i++){
        avg=(arr[i]+avg)/2;
    }
    cout<<avg<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}