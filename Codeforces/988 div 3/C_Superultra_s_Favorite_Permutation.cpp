#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n<5) {cout<<-1<<endl; return;}

    for(int i=1;i<=n;i++){
        if(i%2 and i!=5) cout<<i<<" "; 
    }
    cout<<5<<" "<<4<<" ";
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 ==0 and i!=4)
            cout << i << " ";
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}