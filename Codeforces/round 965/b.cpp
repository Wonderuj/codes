#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    char arr[n][4];
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }

    for (int i = n-1; i >=0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if(arr[i][j]=='#'){
                cout<<j+1<<" ";
            }
        }
    }
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}