/*
Description

Write a program that manipulates a disjoint set S = S1, S2, ..., Sk.

First of all, the program should read an integer n, then make a disjoint set where each element consists of 0, 1, ..., n-1 respectively.

Next, the program should read an integer q and manipulate the set of q queries. There are two kinds of queries for different operations:

unite(x, y): unite sets that contain x and y, say Sx and Sy, into a new set.
same(x, y): determine whether x and y are in the same set.

Input Format

The first line contains two space-separated integers n and q, (1 ≤ n ≤ 104, 1 ≤ q ≤ 105).
Then, q queries are given in the form com x y, where com represents the type of queries. '0' denotes unite and '1' denotes same operation (x != y).


Output Format

For each same operation, print 1 if x and y are in the same set, otherwise 0, in a line.
*/

#include<bits/stdc++.h>
using namespace std;

struct UnionFind{
    int n, *parent, *rank;
    UnionFind(){};

    UnionFind(int a){
        n=a;
        parent=new int[n+1];
        rank=new int [n+1];
        for(int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }

    int find(int x){
        if(x!=parent[x]){
            return parent[x]=find(parent[x]);
        }
        return x;
    }

    int same(int x, int y){
        return (find(x)==find(y)?1:0);
    }

    void unite(int x, int y){
        int xroot=find(x); int yroot= find(y);
        if (xroot != yroot)
        {
            if (rank[xroot] >= rank[yroot])
            {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else
            {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
        }
    }
    void reset(){
        for(int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    UnionFind uf(n);
    while(q--){
        int com ,x,y;
        cin>>com>>x>>y;
        if(com==0){
            uf.unite(x,y);
        }
        else{
            if(x!=y){
                cout<<uf.same(x,y)<<'\n';
            }
        }
    }
    uf.reset();
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}