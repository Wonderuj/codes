// #include <bits/stdc++.h>
// using namespace std;
// int board[14][14];
// int n, k;
// int ans=0 ;
// int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};   //attacking cells difference in row and column

// bool check(int i, int j)
// {
//     if (board[i][j] == 1)  //if there is a knight return 0 -> I cant place a knight there
//     {
//         return 0;
//     }
//     for(int pos=0;pos<8;pos++){
//         //this is new cell of which we will check if knight is there or not, if board[nx][ny] will be 1,
//         //then check will be zero as we cant place our knight there.
//         int nx=i+dx[pos];
//         int ny=j+dy[pos];  //new cells getting attacked (nx,ny)
//         if(nx<n&&nx>=0 && ny<n&&ny>=0 && board[nx][ny]==1){  //nx<n and >0 is us checking if new cell calcuated is on the board or not.
//             return 0;
//         }
//     }
//     return 1;
// }
// void rec(int level)
// { // level is number of knights placed
//     // base case
//     if (level == k)
//     {
//         ans++;
//         // board gives the solution
//         return;
//     }

//     // choices
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (check(i, j))
//             {
//                 board[i][j] = 1;
//                 rec(level + 1);
//                 board[i][j] = 0;
//             }
//         }
//     }
// }
// void solve()
// {
//     cin >> n >> k;
//     rec(0);
//     for(int i=1;i<=k;i++){
//         ans/=i;                           //dividing the answer by k! because in permutation , code is counting knights as diffrent things
//                                         //the level assumes the objects to be different
//     }
//     cout << ans << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }

//-----------------------------------=================================================--------------------====
//----------------------------------------------------------------------------------------------------------

// 2nd

// #include <bits/stdc++.h>
// using namespace std;
// int board[14][14];
// int n, k;
// int ans=0;
// int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dy[] = {2, 1, -1, -2, -2, -1, 1, 2}; // attacking cells difference in row and column

// bool check(int i, int j)
// {
//     if (board[i][j] == 1) // if there is a knight return 0 -> I cant place a knight there
//     {
//         return 0;
//     }
//     for (int pos = 0; pos < 8; pos++)
//     {
//         // this is new cell of which we will check if knight is there or not, if board[nx][ny] will be 1,
//         // then check will be zero as we cant place our knight there.
//         int nx = i + dx[pos];
//         int ny = j + dy[pos]; // new cells getting attacked (nx,ny)
//         if (nx < n && nx >=0 && ny < n && ny >= 0 && board[nx][ny] == 1)
//         { // nx<n and >0 is us checking if new cell calcuated is on the board or not.
//             return 0;
//         }
//     }
//     return 1;
// }
// void rec(int level,int lastx, int lasty)
// { // level is number of knights placed
//     // base case
//     if (level == k)
//     {
//         ans++;
//         // board gives the solution
//         return;
//     }

//     // choices
//     for (int i = lastx; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if(i==lastx && j<=lasty ) continue;     ////we optimized the solution here. checking in the way that knights -
// /// will be placed at a higher value than the previous (last) knight.. so repeated soltuions wont be formed altogether hence no need to divide by k!.
//             if (check(i, j))
//             {
//                 board[i][j] = 1;
//                 rec(level + 1,i,j);
//                 board[i][j] = 0;
//             }
//         }
//     }
// }
// void solve()
// {
//     cin >> n >> k;
//     rec(0,0,-1);           //passing cell which is just behind first cell
//     cout << ans << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }

//----=======================--------------------------------------------------------------===========

// 3rd
#include <bits/stdc++.h>
using namespace std;
int board[14][14];
int n, k;
int ans;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2}; // attacking cells difference in row and column

bool check(int i, int j)
{
    if (board[i][j] == 1) // if there is a knight return 0 -> I cant place a knight there
    {
        return 0;
    }
    for (int pos = 0; pos < 8; pos++)
    {
        // this is new cell of which we will check if knight is there or not, if board[nx][ny] will be 1,
        // then check will be zero as we cant place our knight there.
        int nx = i + dx[pos];
        int ny = j + dy[pos]; // new cells getting attacked (nx,ny)
        if (nx < n && nx >= 0 && ny < n && ny >= 0 && board[nx][ny] == 1)
        { // nx<n and >0 is us checking if new cell calcuated is on the board or not.
            return 0;
        }
    }
    return 1;
}
void rec(int level, int knights)
{ // level is board
    // base case
    if (level == n * n)
    {
        if (knights == 0)
        {
            ans++;
        }
        // we update only when answer is 0
        // board gives the solution
        return;
    }

    /* if (level == n*n && knights == 0)
       {
               ans++; //notice this is wrong as even tho we check the knights = 0 for base case this have to be done
               uptil we reach n*n its wrong because we have to stop at n^2 but count only if knights is 0.
           // board gives the solution
           return;

           and if(knights==0) ans++ will also not suffice as in that recursion wont stop at n2 and will go on indefinately.
       } */ 
    int row = level / n;
    int col = level % n;

    // recursion
    // dont place knight
    rec(level + 1, knights);

    // place
    if (knights > 0 && check(row, col))
    {
        board[row][col] = 1;
        rec(level + 1, knights - 1);
        board[row][col] = 0;
    }
}
void solve()
{
    cin >> n >> k;
    ans = 0;
    rec(0, k);
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}

