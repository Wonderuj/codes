#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin>>n>>s;
    int odd[26]={0}, even[26]={0};

    for(int i=1;i<=n;i++){
        (i%2)?odd[s[i]-'a']++:even[s[i]-'a']++;
    }

    int maxiOdd=0, maxiEven=0;

    for(int i=0;i<26;i++){
        if(odd[i]>odd[maxiOdd]) maxiOdd=i;
        if(even[i]>even[maxiEven]) maxiEven=i;
    }
    int ans=0;
    if(n%2==0){
        ans=(n/2-odd[maxiOdd])+(n/2-even[maxiEven]);
    }
    else{
     
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}