#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int>arr(2*n+1,0);
    if(k==0){
        cout<<"0\n";
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i+j]++;
        }
    }

    sort(arr.begin(),arr.end(),greater<int>());
    // for(auto &x :arr){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<=2*n;i++){
        arr[i]=arr[i]+arr[i-1];
    }
    // for (auto &x : arr)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    auto ans=lower_bound(arr.begin(),arr.end(),k)-arr.begin();
    cout<<ans+1<<endl;    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}