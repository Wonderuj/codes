#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int ptr1=0;
    int ptr2=n-1;

    while(ptr1<ptr2){
        while(ptr1<n-1 && v[ptr1]==0){
            ptr1++;
        }
        while(ptr2>0 && v[ptr2]==1){
            ptr2--;
        }

        if(ptr1<ptr2){
            swap(v[ptr1],v[ptr2]);
            ptr1++;
            ptr2--;
        }
    }
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}