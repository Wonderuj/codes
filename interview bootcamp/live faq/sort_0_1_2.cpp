#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cur=0; 
    int ptr1=0, ptr2=n-1;   //these pointers points the value just ahead of the range of 0's and before the range of 2's from end respectivly

    while(cur<n){
        if(a[cur]==0){
            swap(a[cur],a[ptr1]);
            ptr1++;
            cur++;
        }

       else if(a[cur]==2){
            swap(a[cur],a[ptr2]);
            ptr2--;    
         //we dont update the cur because we dont know what value would have been swapped. If that was 0 we need to swap again at that position.
           
        }
        else{
            //a[cur]==1
            cur++;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}