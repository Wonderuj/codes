#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    cout<<1<<" "<<n-1<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}

//lets say x is a divisor of n (x|n) => n=k.x+0 (by euler's identity) , we need the sum of LCM and GDC to be n, so will n-x work?
// yes, because n=k.x => k.x-x = (k-1).x where k-1 is an integer hence it will also be multiple of x. => x|(n-x) i.e x will be gcd and n-x will be lcm
// since smallest divisor can be 1 , 1 and n-1 will always work.