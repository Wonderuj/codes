#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int k=0;
    long long ans=0;

    map<int,int>mp;
    mp[0]=9;
    for(int i=1;i<=9;i++){
        mp[i]=i-1;
    }

    int ptr=1;

    while(k<4){
        int x=s[k]-'0';
        ans+=1+ abs(mp[x]-mp[ptr]);
        ptr=x;
        k++;
    }
    cout<<ans<<'\n';

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}