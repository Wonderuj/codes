#include<bits/stdc++.h>
using namespace std;
priority_queue<int>pq;

void add(int x){
 return pq.push(x);
}
void remove(){
    if(!pq.empty()){
        pq.pop();
    }
    return;
}
void print(){
    if(!pq.empty()){
        cout<<pq.top()<<endl;
    }
    else{
        cout<<'0'<<endl;
    }
}
void solve(){
    int q;
    cin>>q;
    string s="";
    while(!pq.empty()){
        pq.pop();                   //before each query the globally defined pq have to be cleared
    }
    for(int i=0;i<q;i++){
        cin>>s;
        if(s=="add"){
            int x;
            cin>>x;
            add(x);
        }
        if(s=="remove"){
            remove();
        }
        if(s=="print"){
            print();
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}