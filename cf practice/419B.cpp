#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    int arr[200100];
    memset(arr, 0, sizeof(arr));
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr[x]++;
        arr[y+1]--;
    }
    for(int i=1;i<200100;i++){
        arr[i]+=arr[i-1];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int sum=0;
        for(int i=l;i<=r;i++){
            if(arr[i]>k) sum++;
        }
        cout<<sum<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}