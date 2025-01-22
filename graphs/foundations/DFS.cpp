// #include<bits/stdc++.h>
// using namespace std;
// #define pb push_back
// #define vi vector<int>
// #define vvi vector<vector<int>>
// int n,m;
// //vector<vector<int>>g;
// vvi g;
// vi vis;         //visited vector


// void dfs(int node){
//     vis[node]=1;
//     for(auto v:g[node]){        //loop over all of its neighbour
//         if(!vis[v]){            //if the neighbour is not visied
//             dfs(v);               //visit it
//         }
//     }
// }
// void solve(){
//     cin>>n>>m;
//     g.resize(n+1);
//     vis.resize(n+1);    //or use vis.assign(n+1,0) then we don't have to clear off the vector each time in solve
//     for(int i=0;i<m;i++){
//         int a,b;
//         cin>>a>>b;
//         g[a].pb(b);
//         g[b].pb(a);
//     }
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
//     g.clear();
//     vis.clear();
// }


//now we will mark the different comonents with seperate numbers seperately accordingly taaki hame pata chal jaye vo kis part me he graph ke.
//upar vala code kara ab uske aage kar rha hu. upar vala code as such nahi vo bas basic dfs he.

// #include <bits/stdc++.h>
// using namespace std;
// #define pb push_back
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define rep(i,j,k) for(int i=j;i<=k;i++)
// int n, m;
// // vector<vector<int>>g;
// vvi g;
// vi vis; // visited vector

// void dfs(int node,int comp)
// {
//     vis[node] = comp;
//     for (auto v : g[node])
//     { // loop over all of its neighbour
//         if (!vis[v])
//         {           // if the neighbour is not visied
//             dfs(v,comp); // visit it and mark with current component number
//         }
//     }
// }
// void solve()
// {
//     cin >> n >> m;
//     g.resize(n + 1);
//     vis.resize(n + 1); // or use vis.assign(n+1,0) then we don't have to clear off the vector each time in solve
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].pb(b);
//         g[b].pb(a);
//     }
//     int num_comp =0;
//     rep(i,1,n){                         //we are looping through all the nodes one by one
//         if(!vis[i]){                    //if vo visit nahi hua hoga to hame matalb naya component mila
//             num_comp++;                 // to number of components ko badha dia
//             dfs(i,num_comp);           //aur har baar naye node pe phouch ke use current component number se mark kar dia
//         }
//     }

// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
//     g.clear();
//     vis.clear();
// }


// Now we have to save the edges too, so we save a edge list

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int,int>>
#define rep(i, j, k) for (int i = j; i <= k; i++)
int n, m;
// vector<vector<int>>g;
vvi g;
vi vis; // visited vector

void dfs(int node, int comp)
{
    vis[node] = comp;
    for (auto v : g[node])
    { // loop over all of its neighbour
        if (!vis[v])
        {                 // if the neighbour is not visied
            dfs(v, comp); // visit it and mark with current component number
        }
    }
}
void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1); // or use vis.assign(n+1,0) then we don't have to clear off the vector each time in solve
    vpi edgelist;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        edgelist.pb({a,b});
    }
    int num_comp = 0;
    rep(i, 1, n)
    { // we are looping through all the nodes one by one
        if (!vis[i])
        {                     // if vo visit nahi hua hoga to hame matalb naya component mila
            num_comp++;       // to number of components ko badha dia
            dfs(i, num_comp); // aur har baar naye node pe phouch ke use current component number se mark kar dia
        }
    }

    //now to save number of egdes in each component
    vi num_of_edge(num_comp+1);
    for(auto v:edgelist){                           //edgelist me travel kara, example (2,1)(2,4)(2,5) saved he usme
        num_of_edge[vis[v.first]]++ ;                   //to number of edges ko utne se badha dia us index pe.
    }

    long long sum=0;
    long long ans=0;
    rep(i,1,n){
        ans+=sum*num_of_edge[i];
        sum+= num_of_edge[i];
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
    g.clear();
    vis.clear();
}