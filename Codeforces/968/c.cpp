#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    // sort(s.begin(),s.end());
    int arr[26]={0};
    for(int i=0;i<n;i++){
        arr[s[i]-'a']++;
    }

    for(int i=0;i<n;i++){
        for(int i=0;i<26;i++){
            if(arr[i]>0){
                cout<<char(i+'a');
                arr[i]--;
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