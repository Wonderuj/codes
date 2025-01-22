#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k,x;
    cin>>n>>k>>x;

    int mini=k*(k+1);
    int diff=n-k;
    int maxi=n*(n+1)-(diff)*(diff+1);

    if(mini>2*x || maxi<2*x){ 
        cout<<"NO\n";
    }
    else cout<<"YES\n";

    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}

// 1 2 3 4 5 6 7 8 9  90-12=78/2=39