#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    string s;
    cin>>s;

    int i=0;
    int cnt=0;
    int ans=0;
    while(i<n){
        if(s[i]=='0') cnt++;
        else if(s[i]=='1') cnt=0;
        if(cnt==m){
            i+=(k);
            cnt=0;
            ans++;
        }
        else i++;
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}