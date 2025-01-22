#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int>v1,v2;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            v1.push_back(i);
            if (i != n / i)
            {
                v2.push_back(n / i);
            }
        }
    }
    reverse(v2.begin(),v2.end());
    
    for(auto x:v2){
        v1.push_back(x);
    }
    for(auto x:v1){
        cout<<x<<'\n';
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
   
    //int _t; cin>>_t;while(_t--)
    solve();
}