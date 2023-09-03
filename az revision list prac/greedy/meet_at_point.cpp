#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>&a , pair<int, int> &b){
    return a.second < b.second;
}
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>v;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }

    sort(v.begin(),v.end());
    int x= v[(v.size()/2)].first;

    sort(v.begin(), v.end(),comp);
    int y = v[(v.size() / 2)].second;

    // cout<<x<<" "<<y<<endl;

    long long sum=0;
    for(auto temp:v){
        sum+= abs(x-temp.first)+abs(x-temp.second);
    }
    cout<<sum<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}