// // 1) Basic Floyed Warshal code  //we are taking nodes to be 0- indexed

// #include<bits/stdc++.h>
// using namespace std;

// int dist[401][401];
// void solve(){
//     int n,m;
//     cin>>n>>m;

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(i!=j) dist[i][j]=1e9;  //initialising all dist with 1e9 except from self nodes (dist from i to i is zero)
//         }
//     }

//     //we keep an adjacency matrix

//     for(int i=0;i<m;i++){
//             int a,b,c;
//             cin>>a>>b>>c;
//             dist[a][b]= min(dist[a][b], c);   //there can be multiple edges for same nodes
//     }

//     //main algorithm goes like-

//     for(int k=0;k<n;k++){
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 dist[i][j]= min(dist[i][j], dist[i][k]+dist[k][j]);
//             }
//         }
//     }

//     //we will get complete distance matrix => All Pair Shortest Path. for any shortest path from i to j it will be dist[i][j]

// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }

// - --- -------------------- ------------------------- --------------------------------- ---------------------------------------- --------

// // 2) To print the path

// #include <bits/stdc++.h>
// using namespace std;

// int dist[401][401];
// int par[401][401]; // we keep an parent array

// // par[i][j] means if we go via nodes i -> x -> y ->...... -> par[i][j] -> j
// // that is, in optimal path from i to j , what is the node that reaches j ?  it is par[i][j] (the second last node)

// void printPath(int i, int j){
//     if(i!=j){
//         printPath(i, par[i][j]);
//     }
//     cout<<j<<'\n';
// }   // its like to print path of i to j, so go in recursion, print path of i to par[i][j] and then print j.

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (i != j)
//                 dist[i][j] = 1e9;
//         }
//     }

//     for (int i = 0; i < m; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         dist[a][b] = min(dist[a][b], c);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             par[i][j] = i; // we just initialise it with i randomly, as dist is already 1e9 so it doesnt matter.
//         }
//     }

//     for (int k = 0; k < n; k++)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (dist[i][j] > dist[i][k] + dist[k][j])
//                 { // we check that if the edge is going to be relaxed
//                     dist[i][j] = dist[i][k] + dist[k][j];
//                     par[i][j] = par[k][j];
//                 }
//             }
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
// }

// - --- --- ----------------- --------------- ---------- ------- ---------- ---------------- ---------------- --------- --------------- --------

// 3) To find rechability of node from i to j.. if theres a path from i to j or not

// #include <bits/stdc++.h>
// using namespace std;

// int dist[401][401];
// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (i != j)
//                 dist[i][j] = 1e9;
//         }
//     }

//     // we keep an adjacency matrix

//     for (int i = 0; i < m; i++)
//     {
//         int a, b; // we dont need weights this time
//         cin >> a >> b;
//         dist[a][b] = 1; // it means theres an edge (path) from a to b
//     }

//     // main algorithm goes like-

//     for (int k = 0; k < n; k++)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
//             }
//         }
//     }
//     // if theres a path from i to j so its already 1 or if theres a path via any intermediate node, then update the dist[i][j] as true or 1.
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }

// - --- --- ----------------- --------------- ---------- ------- ---------- ---------------- ---------------- --------- --------------- --------

// (4) To find shortest cycle, (5) check if theres a negative cycle, (6) Diameter of graph

#include <bits/stdc++.h>
using namespace std;

int dist[401][401];
void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = 1e9;
            // I dont initialize a path from i to i as 0,
            // so if theres a cycle (i.e we can reach i again with a cycle, so distance will be upadted from 1e9)
        }
    }

    // we keep an adjacency matrix

    for (int i = 0; i < m; i++)
    {
        int a, b; // we dont need weights this time
        cin >> a >> b;
        dist[a][b] = 1; // it means theres an edge (path) from a to b
    }

    // main algorithm goes like-

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dist[i][i]); // shortest cycle length
    }

    // to check if theres a negative cycle

    if (ans < 0)
    {
        cout << "Negative Cycle\n";
    }
    else
    {
        cout << "No negative cycle\n";
    }

    //to find diameter of graph
    int diameter = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] != 1e9)
            {

                diameter = max(diameter, dist[i][j]);
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}
