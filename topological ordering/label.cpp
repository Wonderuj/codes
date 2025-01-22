#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>g;
vector<int>label;
vector<int>indeg;
int bfs(int node, int comp){
    priority_queue<int>pq;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            pq.push(-i);
        }
    }
    while(!pq.empty()){
        int cur=-pq.top();
        pq.pop();
        for (auto v :g[cur]){
            indeg[v]--;
            if(indeg[v]==0){
                pq.push(-v);
            }
        }
        comp++;
        label[cur]=comp;
        
    }
    return comp;
}


void solve(){
    cin>>n>>m;
    g.resize(n+1);
    indeg.assign(n+1,0);
    label.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
    }
    int comp=0;
    for(int i=1;i<=n;i++){
        if(!label[i]){
            int a=bfs(i,comp);
            comp=a;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<label[i]<<" ";
    }


}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}