#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int arr[26]={0};
    // set<char>st;
    for(auto x:s){
        arr[x-'a']++;
        // st.insert(x);
    }
    // if(st.size()==1) {
    //     cout<<"First";
    //     return;
    // }

    int diffs=0;
    for(int i=0;i<26;i++){
        diffs+=(arr[i]%2);
    }
    if(diffs%2 or diffs<=1) cout<<"First\n";
    else cout<<"Second\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}