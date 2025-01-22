// https://www.youtube.com/watch?v=zx5Sw9130L0 -Concept

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
void solve(){
    int n;
    cin>>n;
    long long area=0;
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    stack<pair<int,int>>st;   //to save index from which the current element start forming the area (left side of current element)
    for(int i=0;i<n;i++){

        if((!st.empty() && st.top().S< h[i]) ||st.empty()){ //if current element is greater than stack top
            st.push({i,h[i]});                         //we push it into stack as it starts to form area from thst index only
        }

        else if (!st.empty() && st.top().S > h[i])      //if current element is less than stack top
        {
            int temp;                               //this will store index of previous element (the start index) from which we start making area
            while (!st.empty() && st.top().S > h[i]){
                temp=st.top().F;                        //saving the top elements index if its gonna get popped.
                area= max(area, (i- st.top().F)*st.top().S);
                st.pop();
            }
            st.push({temp,h[i]}); 
        } 

    }
    while(!st.empty()){
        area = max(area, (n - st.top().F)*st.top().S);
        st.pop();
    }
    cout<<area<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}

