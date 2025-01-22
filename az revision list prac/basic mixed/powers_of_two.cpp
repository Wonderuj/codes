/*Question
You are given an array A of N integers. Find the number of pairs (i, j) such that i < j and Ai + Aj is a power of 2.
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int count =0;
    for(int i=0;i<n;i++){ 
        
        int prod=1;
        for(int j=1;j<=31;j++){
            prod*=2;
            count+=(mp[prod-v[i]]);
        }
        mp[v[i]]++;
    }
    cout<<count<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}