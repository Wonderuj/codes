#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int x=(n+m)/2;

    set<int>st;
    
    int sum=0;
    for(int i=0;i<=1000;i++){
        sum+=i;
        st.insert(sum);
    }
    int ans=0;
    for(int i=1;i<=x;i++){
        if(st.find(x-i)!=st.end()){
            ans++;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}