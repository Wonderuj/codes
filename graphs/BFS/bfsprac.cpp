// // #include<bits/stdc++.h>
// // using namespace std;
// // #define vi vector<int>
// // #define vvi vector<vi>
// // #define rep0(i, n, m) for (int i = n; i < m; i++)
// // #define rep1(i, n, m) for (int i = n; i <= m; i++)
// // #define F first
// // #define S second
// // using ii = pair<int, int>;


// // int n,m;
// // vector<string> arr;

// // int dx[] = {1, 0, -1, 0};
// // int dy[] = {0, 1, 0, -1};
// // int dist[1010][1010];

// // bool inside(int x, int y){
// //     if(x<0||x>=n||y<0||y>=m||arr[x][y]=='#'){
// //         return 0;
// //     }
// //     else return 1;
// // }
// // void bfs(ii st){
// //     rep0(i,0,n){
// //         rep0(j,0,m){
// //             dist[i][j]=1e9;
// //         }
// //     }
// //     dist[st.F][st.S]=0;
// //     queue<ii> q;
// //     q.push(st);
// //     while(!q.empty()){
// //         ii cur=q.front();
// //         q.pop();
// //         int curd= dist[cur.F][cur.S];

// //         rep0(k,0,4){
// //             ii neigh = {cur.F + dx[k], cur.S + dy[k]};
           
// //             if (!inside(neigh.F, neigh.S))
// //             {
// //                 continue;
// //             }
// //             // if (!inside(cur.F + dx[k], cur.S + dy[k]))
// //             // {
// //             //     continue;
// //             // }
// //             // ii neigh={cur.F+dx[k], cur.S+dy[k]};
// //             if(dist[neigh.F][neigh.S]>curd+1){
// //                 dist[neigh.F][neigh.S] = curd + 1;
// //                 q.push(neigh);
// //             }
// //         }
// //     }


// // }


// // void solve(){
// //     cin>>n>>m;
// //     arr.resize(n);
// //     ii st, en;
// //     rep0(i,0,n){
// //         cin>>arr[i];
// //         rep0(j,0,m){
// //             if(arr[i][j]=='S'){
// //                 st={i,j};
// //             }
// //             if (arr[i][j] == 'E')
// //             {
// //                 en = {i, j};
// //             }
// //         }
// //     }
// //     bfs(st);
// //     cout<<dist[en.F][en.S]<<endl;
// // }
// // signed main(){
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);cout.tie(0);

// //     //int _t; cin>>_t;while(_t--)
// //     solve();
// // }

// // //----------------------------------------------------------------------------------------------------------------
// // //to trace the path and 8 directions (diagnols allowed)

// // #include <bits/stdc++.h>
// // using namespace std;
// // #define vi vector<int>
// // #define vvi vector<vi>
// // #define rep0(i, n, m) for (int i = n; i < m; i++)
// // #define rep1(i, n, m) for (int i = n; i <= m; i++)
// // #define F first
// // #define S second
// // using ii = pair<int, int>;

// // int n, m;
// // vector<string> arr;

// // int dx[] = {1,1,1, 0, -1,-1,-1, 0};
// // int dy[] = { 1, 0, -1, -1, -1, 0,1, 1};
// // int dist[1010][1010];
// // ii par[1010][1010];        //parent array


// // bool inside(int x, int y)
// // {
// //     if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == '#')
// //     {
// //         return 0;
// //     }
// //     else
// //         return 1;
// // }
// // void bfs(ii st)
// // {
// //     rep0(i, 0, n)
// //     {
// //         rep0(j, 0, m)
// //         {
// //             dist[i][j] = 1e9;
// //         }
// //     }
// //     dist[st.F][st.S] = 0;
// //     queue<ii> q;
// //     q.push(st);
// //     while (!q.empty())
// //     {
// //         ii cur = q.front();
// //         q.pop();
// //         int curd = dist[cur.F][cur.S];

// //         rep0(k, 0, 8)
// //         {
// //             ii neigh = {cur.F + dx[k], cur.S + dy[k]};

// //             if (!inside(neigh.F, neigh.S))
// //             {
// //                 continue;
// //             }
// //             if (dist[neigh.F][neigh.S] > curd + 1)
// //             {
// //                 dist[neigh.F][neigh.S] = curd + 1;
// //                 par[neigh.F][neigh.S]=cur;
// //                 q.push(neigh);
// //             }
// //         }
// //     }
// // }

// // void solve()
// // {
// //     cin >> n >> m;
// //     arr.resize(n);
// //     ii st, en;
// //     rep0(i, 0, n)
// //     {
// //         cin >> arr[i];
// //         rep0(j, 0, m)
// //         {
// //             if (arr[i][j] == 'S')
// //             {
// //                 st = {i, j};
// //             }
// //             if (arr[i][j] == 'E')
// //             {
// //                 en = {i, j};
// //             }
// //         }
// //     }
// //     bfs(st);
// //     //cout << dist[en.F][en.S] << endl;
// //     // rep0(i, 0, n)
// //     // {
// //     //     rep0(j, 0, m)
// //     //         cout<<dist[i][j]<<'\t';          to print the grid with all the distances from start
// //     // } cout<<endl;
// //     ii temp=en;
// //     vector<ii> path;
// //     while (temp!=st){   
// //         path.push_back(temp);
// //         temp=par[temp.F][temp.S];   
// //     }
// //     path.push_back(st);
// //     reverse(path.begin(),path.end());
// //     for (auto v:path){
// //         cout<<v.F<<" "<<v.S<<endl;
// //     }

// // }
// // signed main()
// // {
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);
// //     cout.tie(0);

// //     // int _t; cin>>_t;while(_t--)
// //     solve();
// // }

// //----------------------------------------------------------------------------------------------------------------
// // to trace the path and we have Knight moves. The only change is the directional vectors dx and dy 

// #include <bits/stdc++.h>
// using namespace std;
// #define vi vector<int>
// #define vvi vector<vi>
// #define rep0(i, n, m) for (int i = n; i < m; i++)
// #define rep1(i, n, m) for (int i = n; i <= m; i++)
// #define F first
// #define S second
// using ii = pair<int, int>;

// int n, m;
// vector<string> arr;

// int dx[] = {2,1,-1,-2,-2,-1,1,2};
// int dy[] = {-1,-2,-2,-1,1,2,2,1};
// int dist[1010][1010];
// ii par[1010][1010]; // parent array

// bool inside(int x, int y)
// {
//     if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == '#')
//     {
//         return 0;
//     }
//     else
//         return 1;
// }
// void bfs(ii st)
// {
//     rep0(i, 0, n)
//     {
//         rep0(j, 0, m)
//         {
//             dist[i][j] = 1e9;
//         }
//     }
//     dist[st.F][st.S] = 0;
//     queue<ii> q;
//     q.push(st);
//     while (!q.empty())
//     {
//         ii cur = q.front();
//         q.pop();
//         int curd = dist[cur.F][cur.S];

//         rep0(k, 0, 8)
//         {
//             ii neigh = {cur.F + dx[k], cur.S + dy[k]};

//             if (!inside(neigh.F, neigh.S))
//             {
//                 continue;
//             }
//             if (dist[neigh.F][neigh.S] > curd + 1)
//             {
//                 dist[neigh.F][neigh.S] = curd + 1;
//                 par[neigh.F][neigh.S] = cur;
//                 q.push(neigh);
//             }
//         }
//     }
// }

// void solve()
// {
//     cin >> n >> m;
//     arr.resize(n);
//     ii st, en;
//     rep0(i, 0, n)
//     {
//         cin >> arr[i];
//         rep0(j, 0, m)
//         {
//             if (arr[i][j] == 'S')
//             {
//                 st = {i, j};
//             }
//             if (arr[i][j] == 'E')
//             {
//                 en = {i, j};
//             }
//         }
//     }
//     bfs(st);
//      cout << dist[en.F][en.S] << endl;
//     //  rep0(i, 0, n)
//     //  {
//     //      rep0(j, 0, m)
//     //          cout<<dist[i][j]<<'\t';          to print the grid with all the distances from start
//     //  } cout<<endl;
//     ii temp = en;
//     vector<ii> path;
//     while (temp != st)
//     {
//         path.push_back(temp);
//         temp = par[temp.F][temp.S];
//     }
//     path.push_back(st);
//     reverse(path.begin(), path.end());
//     for (auto v : path)
//     {
//         cout << v.F << " " << v.S << endl;
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

