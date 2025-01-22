// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int ans=0, l=0;
//     map<int,int>mp;

//     for(int i=0;i<n;i++){
//         while(mp[arr[i]]==1){           //if the element at i already have frequency more than 1, then
//             mp[arr[l]]--;               //decrease the frequency of current element at l and increaase l
//             l++;                        //(move it towards right)until that element is no longer in map
//         }
//         mp[arr[i]]++;
//         ans=max(ans, i-l+1);
//     }
//     cout<<ans<<'\n';
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     int _t; cin>>_t;while(_t--)
//     solve();
// }


#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int freq[n];
    for(int i=0;i<n;i++){
        cin>>freq[i];
    }
    int head=-1, tail=0, ans=0;
    map<int,int>mp;    //or we can also use unordered map
    while(tail<n){
        while(head+1<n && mp[freq[head+1]]!=1){
            head++;
            mp[freq[head]]++;
        }
        ans=max(ans, head-tail+1);
        if(head>=tail){
            mp[freq[tail]]--;
            tail++;
        }

        else{
            tail++;
            head=tail-1;
        }

    }
    cout<<ans<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}