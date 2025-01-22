#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define rep0(i,n,m) for(int i=n;i<m;i++)
#define rep1(i,n,m) for(int i=n;i<=m;i++)


vi col;
vvi g;
vi parent;
vi any_cycle;
vi cntcycle;
vi prefixorder;
bool is_cycle=0;
void dfs(int node,int par){
    parent[node]=par;
    col[node]=2;
    for(auto v: g[node]){
       // if(v==parent[node]) continue;  //in case of undirected graph
        if(col[v]==1){      //node -v is forward egde
            dfs(v,node);
        }
        else if(col[v]==2){  //node -v is back edge  
        //we found a cycle
        cout<<"HIT : "<<node<<endl;
        if(is_cycle==0){
            int temp=node;
            while(temp!=v){        //v is the cycle end(or start) and current node is the last member of cycle which connects to start 
                any_cycle.pb(temp);
                temp=parent[temp];
            }                                           //we traversed back in a cycle by using parent nodes saved in parent array
            any_cycle.pb(temp);
            reverse(any_cycle.begin(),any_cycle.end());
        }
        cntcycle[node]++;
        cntcycle[parent[v]]--;
        is_cycle=1;
        }
        else if( col[v]==3){        //node -v is cross edge
            //unimportant
        }
    }
    col[node]=3;
    prefixorder.pb(node);    //order in which they become 3 is order in which we do the prefix sum part to count the number of nodes that are in any cycle
}
void solve(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,1);
    parent.assign(n+1,0);
    cntcycle.assign(n + 1, 0);
    rep0(i,0,m){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);

        //in case of undirected add g[b].pb(a) also
    }
    rep1(i,1,n){
        if(col[i]==1){  //if node is unvisited then dfs that perticular node
            dfs(i,0);
        }
    }
    for(auto v: any_cycle){
        cout<<v<<" ";
    }
    cout<<endl;
    for(auto v: prefixorder){
        cntcycle[parent[v]]+=cntcycle[v];       
    }
    int cntnodes=0;
    rep1(i,1,n){
        if(cntcycle[i]>0){
            cntnodes++;
        }
    }
    cout<<cntnodes<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}