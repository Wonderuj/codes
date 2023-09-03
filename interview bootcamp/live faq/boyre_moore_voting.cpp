// T.C -> O(N), S.C -> O(1)

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int majority=-1;
    int count=0;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(!count){
            majority=x;
            count=1;
        }
        else if (majority==x)
        {
            count++;
        }
        else{
            count--;
        }
    }
    cout<<majority<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}