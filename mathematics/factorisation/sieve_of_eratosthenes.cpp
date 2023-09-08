//to print all numbers that are prime in range 1-N

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int isPrime[100100];
    for(int i=2;i<=n;i++){
        isPrime[i]=1;
    }

    for(int i=2;i<=n;i++){
        if(isPrime[i]==1){
            for(int j=1LL*i*i ;j<=n; j+=i){
                isPrime[j]=0;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(isPrime[i]==1){
            cout<<i<<" ";
        }
    }
    cout<<endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}