#include<bits/stdc++.h>
using namespace std;

vector<int>nextgreater(vector<int>&arr){
    stack<int>st;
    int n=(int)arr.size();
    vector<int>ans(n);

    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=(st.top());
        }
        else{
            ans[i]=(-1);
        }
        st.push(arr[i]);
    }

    return ans;
}

void solve(){
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}