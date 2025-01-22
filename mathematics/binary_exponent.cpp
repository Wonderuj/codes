//this is to calculate a^n in log(n) time

#include<bits/stdc++.h>
using namespace std;

int MOD=1e9+7;

int binpow(int a, int n, int mod){
    if(n==0) return 1;
    if(n%2==1){
        return a*binpow(a,n-1,mod)%mod;
    }
    else{
        int temp=binpow(a,n/2,mod); 
        return temp*temp%mod;
    }
}

//a.b^-1  //uses fermat little theorm 
int inverse(int x)
{
    return binpow(x, MOD- 2,MOD);
}

void solve(){

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}