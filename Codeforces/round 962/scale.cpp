#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> v(n, vector<int>(n));

    string s[n];

    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    for(int i=0;i<n;i+=k){
        for(int j=0;j<n;j+=k){
            cout<<s[i][j];
        }
        cout<<endl;
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}