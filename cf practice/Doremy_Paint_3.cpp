#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    int sz=mp.size();

    if(sz>2){
        cout<<"NO\n";
        return;
    }
    else if(sz==1){
        cout<<"YES\n";
        return;
    }

    bool flag=false;
    
    for(auto& [num,freq]:mp){
        if(freq==n/2){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}