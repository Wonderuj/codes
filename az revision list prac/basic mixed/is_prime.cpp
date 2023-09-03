#include<bits/stdc++.h>
using namespace std;
#define int long long
bool checkprime(int x){
    if (x <= 1)
    {
        return false;          //while solving I forgot this edge case
    }
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
void solve(){
    int n;
    cin>>n;
    if(checkprime(n)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}