#include<bits/stdc++.h>
using namespace std;

int n, k;
bool check(int x){
    int num=1;
    while(x--){
        num*=k;
    }
    return (num>=n);
}

void solve(){
    
    cin>>n>>k;
    

    vector<int>arr;
    for(int i=1;i<=1+log(n);i++){
        arr.push_back(i);
    }

    int lo=0, hi=n-1;
    int ans=n;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(mid)){
            hi=mid-1;
            ans=mid;
        }
        else lo=mid+1;
    }

    int temp=ans;
    int num = 1;
    while (temp--)
    {
        num *= k;
    }
    n-=num;
    if(num==0) cout<<1<<endl ;
    else {
        
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}



