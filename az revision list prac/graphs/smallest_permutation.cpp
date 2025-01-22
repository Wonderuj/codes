#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
int n, m;
vector<int> indeg;
vector<int> topo;
void kahn(){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=1;i<=n;i++){
        if(!indeg[i]){
            pq.push(i);
        }

    }
    while(!pq.empty()){
        int cur=pq.top();
        pq.pop();
        topo.push_back(cur);
        for(auto v:g[cur]){
            indeg[v]--;
            if(!indeg[v]){
                pq.push(v);
            }
        }
    }
}

void solve(){
    
    cin>>n>>m;
    g.resize(n+1);
    indeg.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
    }

    kahn();
    if(topo.size()!=n){
        cout<<"-1\n";
    }
    else{
        for(auto v: topo){
            cout<<v<<" ";
        }
        cout<<'\n';
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}