#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int x = n / 2;
    cout << x << '\n';
    if(n%2==0){
        for(int i=0;i<x;i++){
            cout<<2<<" ";
        }
    }
    else{
        for (int i = 0; i < x-1; i++)
        {
            cout << 2 << " ";
        }
        cout<<3<<'\n';
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}