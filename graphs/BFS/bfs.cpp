// // Implicit graph bfs (when graph is given input as a grid)
// #include <bits/stdc++.h>
// using namespace std;
// #define vi vector<int>
// #define vvi vector<vi>
// #define rep0(i, n, m) for (int i = n; i < m; i++)
// #define rep1(i, n, m) for (int i = n; i <= m; i++)
// #define F first
// #define S second
// using ii = pair<int, int>;

// /*
// 6 6
// S.#...
// ......
// ####.#
// E.##.#
// ..#..#
// #....#
// */
// int n, m;
// vector<string> arr;

// // directional vectors
// /*
//                             (x-1,y)
//  __ y                          |
// |                       (x,y-1)--(x,y+1)
// x                              |
//                             (x+1,y)
// */

// int dx[] = {1, 0, -1, 0}; // x+dx[i], y+dy[i] will give the coordinates of 4 directions
// int dy[] = {0, 1, 0, -1};

// bool inside(int x, int y)
// { // check if cell is valid or not
//     if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == '#')
//         return 0;
//     else
//         return 1;
// }
// int dist[1010][1010]; // a distance array from each cell from starting cell

// void bfs(ii st)      //BFS
// { // function has input of pair of numbers which are coordinates of starting cell
//     rep0(i, 0, n)
//     {
//         rep0(j, 0, m)
//         {
//             dist[i][j] = 1e9; // initially asumming every cell have infinte distacne from the start
//         }
//     }
//     dist[st.F][st.S] = 0;
//     queue<ii> q;
//     q.push(st);
//     while (!q.empty())
//     {
//         ii cur = q.front();
//         q.pop();
//         int curd = dist[cur.F][cur.S];   //current distance
//         rep0(k, 0, 4)
//         {
//             if (!inside(cur.F + dx[k], cur.S + dy[k]))
//             {
//                 continue;
//             }
//             ii neigh = {cur.F + dx[k], cur.S + dy[k]};
//             // if(dist[neigh.F][neigh.S]==1e9){    //unvisited node
//             //     dist[neigh.F][neigh.S] = curd+1      //then visit the distace with current distace +1 (as it is a neighbour)
//             // } or better way to write is:
//             if (dist[neigh.F][neigh.S] > curd + 1) // relaxing condition that,is the current path better than other paths???
//             {
//                 dist[neigh.F][neigh.S] = curd + 1; // then visit the distace with current distace +1 (as it is a neighbour)
//                    q.push(neigh);
//             }
            
//         }
//     }
// }

// void solve()
// {
//     cin >> n >> m;
//     arr.resize(n);
//     ii st, en; // starting and ending cell coordinates
//     rep0(i, 0, n)
//     {
//         cin >> arr[i]; // loop over all the rows and taking whole row as string input
//         rep0(j, 0, m)
//         {
//             if (arr[i][j] == 'S')
//             {
//                 st = {i, j};
//             }
//             else if (arr[i][j] == 'E')
//             {
//                 en = {i, j};
//             }
//         }
//     }
//     bfs(st);
//     cout << dist[en.F][en.S] << endl; // printing distance of starting to ending cell from distance array
// }

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }



//-----------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define rep0(i, n, m) for (int i = n; i < m; i++)
#define rep1(i, n, m) for (int i = n; i <= m; i++)
#define F first
#define S second
using ii = pair<int, int>;

/*
6 6
S.#...
......
####.#
E.##.#
..#..#
#....#
*/
int n,m;
vector<string> arr;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
ii dist[1010][1010];       //in this pair first one is the distance and second is number of optimal paths from start till this.
ii par[1010][1010];

bool inside(int x, int y){
    if(x<0||x>=n||y<0||y>=m||arr[x][y]=='#'){
        return 0;
    }
    else return 1;
}
void bfs(ii st){
    rep0(i,0,n){
        rep0(j,0,m){
            dist[i][j]={1e9,0};        //initally putting 0 paths in every cell
        } 
    }
    dist[st.F][st.S]={0,1};     //only one path at start.
    queue<ii> q;
    q.push(st);
    while(!q.empty()){
        ii cur=q.front();
        q.pop();
        int curd= dist[cur.F][cur.S].F;

        rep0(k,0,4){
            ii neigh = {cur.F + dx[k], cur.S + dy[k]};

            if (!inside(neigh.F, neigh.S))
            {
                continue;
            }
            // if (!inside(cur.F + dx[k], cur.S + dy[k]))
            // {
            //     continue;
            // }
            // ii neigh={cur.F+dx[k], cur.S+dy[k]};
            if(dist[neigh.F][neigh.S].F >curd+1){
                dist[neigh.F][neigh.S] = {curd + 1, dist[cur.F][cur.S].S};   //whatever the all of the optimal paths were there till this cur node, gets extended by one if its better than previous node
                par[neigh.F][neigh.S]=cur;
                q.push(neigh);
            }   //if first one is bigger then update it, and if its equal then add the second result (this is the if-else statement)
            else if (dist[neigh.F][neigh.S].F == curd + 1){
                dist[neigh.F][neigh.S].S += dist[cur.F][cur.S].S;
            }
        }
    }

}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    ii st, en;
    rep0(i,0,n){
        cin>>arr[i];
        rep0(j,0,m){
            if(arr[i][j]=='S'){
                st={i,j};
            }
            if (arr[i][j] == 'E')
            {
                en = {i, j};
            }
        }
    }
    bfs(st);
    cout << dist[en.F][en.S].F << " " << dist[en.F][en.S].S << endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}
