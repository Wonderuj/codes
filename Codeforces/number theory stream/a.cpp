//https://codeforces.com/gym/307293


#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n%2){
        cout<<9<<" "<<n-9<<endl;
    }
    else {
        cout<<4<<" "<<n-4<<endl;
    }
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}