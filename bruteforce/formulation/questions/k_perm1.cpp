#include<bits/stdc++.h>
using namespace std;
int n,k;
map<int,int>mp;
vector<int>cs;
// vector<vector<int>>as;
int ans=0;
void rec(int level){
    //base case
    if(level==n){
        // as.push_back(cs);
        ans++;
        if(ans==k){
            for(auto v:cs){
                cout<<v<<" ";
            } cout<<endl;
        }
        return;
    }

    //recursion
    for(auto v:mp){
        if(v.second!=0){
            mp[v.first]--;
            cs.push_back(v.first);
            rec(level+1);
            cs.pop_back();
            mp[v.first]++;
        }
    }

}



void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        mp[i]++;
    }
    rec(0);

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}