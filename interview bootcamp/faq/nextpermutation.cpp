#include<bits/stdc++.h>
using namespace std;

void nextpermut(vector<int>&a){
    int n=(int)a.size();
    int idx=-1;

    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            idx=i;    //we found the infection point
            break;
        }
    }

    if(idx==-1){        //reversing if whole string is in decreasing order {4,3,2,1 to 1,2,3,4}
        reverse(a.begin(), a.end());
        return;
    }

    for(int i=n-1;i>idx;i--){ //swapping infection point with element just greater than it for next permutation
        if(a[idx]<a[i]){
            swap(a[i],a[idx]);
            break;
        }
    }   

    int l=idx+1, r=n-1;
    while(l<=r){
        swap(a[l],a[r]);  //reversing the remaining string as it will be in decreasing order but we needed next greater.
        l++,r--;
    }
    // 1 3 4 5 2 -> 1 3 5 2 4 -> 1 3 5 4 2 -> 1 5 4 3 2 -> 2 5 4 3 1
}

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    nextpermut(a);
    for(auto u:a){
        cout<<u<<" ";
    }
    // for (int i = 0; i < 4; i++)
    // {
    //     a[i]=i+1;
    // }
    // for (int i = 0; i < 25; i++)
    // {
    //     for(auto u:a){
    //         cout<<u<<" ";
    //     }
    //     cout<<endl;
    //     nextpermut(a);  
    // }
    

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}