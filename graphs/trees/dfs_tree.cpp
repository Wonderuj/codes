#include<bits/stdc++.h>
using namespace std;

vector<int> g[100100];   //array of vectors
int dep[100100];   //saving the depths
int par[100100];   //saving the parent node
bool isLeaf[100100];
int subtreeSz[100100];
int numChild[100100]; 

void dfs(int node, int parent, int depth){
    dep[node]=depth;
    par[node]=parent;

    subtreeSz[node]=1;

    numChild[node]=0;
    for(auto v:g[node]){
        if(v!=parent){  //if neighbour of the node is not a parent, it means it is inside subtree of a tree, it means its a child
            numChild[node]++;
            dfs(v,node,depth+1);  
            //if the dfs worked correctly, we would have updated subtree size of child node, so we can directily add that for subtree size of node.
            subtreeSz[node]+=subtreeSz[v];
        }   

    }
    if(numChild[node]==0){
        isLeaf[node]=1;
    }
}
void solve(){
    int n;  
    cin>>n;
    for(int i=0;i<n-1;i++){      //we know that if there n nodes, so in a tree there will be n-1 edges
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);   //trees by default are undirected
    }
    dfs(1,0,0);          //we say let the root be the node 1, so we dfs at 1, its parent is supposed to be 0
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}


//if we want distance from any node u to v just call dfs(u,0,0) and depth[v] will give me distance from u to v after dfs
