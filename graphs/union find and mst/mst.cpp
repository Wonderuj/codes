#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    int n, set_size, *parent, *rank;

    UnionFind(){};
    UnionFind(int a)
    {
        n = a;
        set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if (x != parent[x])
        {
            return parent[x] = find(parent[x]);
        }
        return x;
    }

    void merge(int x, int y)
    {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot != yroot)
        {
            if (rank[xroot] >= rank[yroot])
            {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else
            {
                parent[xroot] = parent[yroot];
                rank[yroot] += rank[xroot];
            }
            set_size -= 1;
        }
    }

    void reset()
    {
        set_size = n;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int size()
    {
        return set_size;
    }

    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " -> " << parent[i] << '\n';
        }
    }
};

vector<pair<int,int>>g[100010];   //to make the tree of mst in case we need it
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>edgelist;
    UnionFind uf(n);
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        edgelist.push_back({c,{a,b}});
    }

    sort(edgelist.begin(),edgelist.end());

    int mst_cost=0;
    int cnt=0;
    for(auto v:edgelist){
        int x= v.second.first;
        int y=v.second.second;
        int wt=v.first;
        if(uf.find(x)!=uf.find(y)){
            uf.merge(x,y);
            mst_cost+=wt;
            cnt++;        //this is to check later on that wheater mst exist or not.
            g[x].push_back({y,wt});
            g[y].push_back({x,wt}); //tree is undirected in nature .. also g stores the tree of mst by this now
        }
    }
  
    if(cnt!=n-1){            //in a tree there should be n-1 edges
        cout<<"NO MST\n";
        return;
    }
    cout<<mst_cost<<endl; 
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}