#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    string s1,s2;
    cin>>s1>>s2;
    vector<int>v(n);

    map<char,int>mp1,mp2;

    for(int i=0;i<n;i++){
        //s1 compare
        if(mp2[s1[i]]!=0){
            v[i]++;
        }
        mp1[s1[i]]++;
        
    //s2 compare
        if(mp1[s2[i]]!=0){
            v[i]++;
        }
        mp2[s2[i]]++;
    }

    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        v[i]+=v[i-1];
    }
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}