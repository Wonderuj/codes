// /*Question
// You are given a map of a building, and your task is to count the number of its rooms.
// The size of the map is n × m squares, and each square is either floor or wall.
// You can walk left, right, up, and down through the floor squares.

// Input Format

// The first input line has two integers n and m: the height and width of the map.
// Then there are n lines of m characters describing the map. Each character is either ‘.’ (floor) or '#' (wall).

// Sample Input 1

// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

// Sample Output 1

// 3
// */

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> g;

int vis[1010][1010];

int dx[4]={0,-1,1,0};
int dy[4]={-1,0,0,1};

bool inside(int x,int y){
    if(x>=0 && x<n &&y>=0 &&y<m && g[x][y]!='#'){
        return true;
    }
    return false;
}
void dfs(int x, int y)
{
    // cout<<"i am at"<< x <<" "<<y<<endl;
    vis[x][y]=1;
    for(int k=0;k<4;k++){
        if (inside(x + dx[k], y + dy[k]) && !vis[x + dx[k]][y + dy[k]])
        {
            dfs(x + dx[k], y + dy[k]);
        }
    }
    return;
    
}

void solve()
{
    cin >> n >> m;
    g.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '#')
            {
                vis[i][j] = 1;
            }
            else
            {

                vis[i][j] = 0;
            }
        }
    }

    int comp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                comp++;
                dfs(i, j);
            }
        }
    }

    cout<<comp<<'\n';
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}



