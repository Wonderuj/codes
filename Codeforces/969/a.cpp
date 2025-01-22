#include<bits/stdc++.h>
using namespace std;

void solve(){
    int l, r;
    cin >> l >> r;
    int x = l / 2, y = (r + 1) / 2;
    cout << (y - x) / 2 << endl;
}


signed main(){
    ios_base::sync_with_stdio(0);  
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}