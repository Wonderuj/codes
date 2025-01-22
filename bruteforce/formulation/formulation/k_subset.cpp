#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int>arr;
vector<int> sol;
void rec(int level){
    //base case                                         //O(nCk)
    if(level==n){
        if(sol.size()==k){
            for(auto v:sol){
                cout<<v<<" ";
            } cout<<endl;
        }
        return;
    }

    //recursive case
    //decide for arr[level]..

    //take
    if(sol.size()<k)  //check
    {
        sol.push_back(arr[level]);
        rec(level + 1);
        sol.pop_back();
    }

    //dont take
    rec(level+1);
}

void solve(){
    cin>>n>>k;
    arr.resize(n);
    for(int i=0;i<n;i++){ cin>>arr[i];}
    rec(0);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}