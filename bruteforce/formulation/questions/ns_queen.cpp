// //N S-queens on n*n chessboard

// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int board[14][14];

// bool check(int row, int col){
//     for(int i=0;i<n;i++){

//     }
// }
// int rec(int level, int queens){
//     //base case
//     int ans=0;
//     if(level==n*n){
//         if(queens==0){
//             ans++;
//         }
//     return;
//     }

//     //defining row and column coordinates from index
//     int row=level/n; int col=level%n;

//     //dont place
//     rec(level+1, queens);  
    
//     //place
//     if(check(row,col) &&queens>0){
//         board[row][col]=1;
//         rec(level+1, queens-1);
//         board[row][col]=0;
//     }
// }
// void solve(){
//     cin>>n;
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
const ll mod = 1e9 + 7;
const int N = 100100;

int n;
vector<int> queens;
int ans = 0;

bool check(int level, int col)
{
    for (int prow = 0; prow < level; prow++)
    {
        int pcol = queens[prow];
        if (pcol == col || abs(prow - level) == abs(pcol - col))
        {
            return false;
        }
        else if (((abs(prow - level) == 2) && (abs(pcol - col) == 1)) || (abs(prow - level) == 1) && (abs(pcol - col) == 2))
        {
            return false;
        }
    }
    return true;
}

void solve(int level)
{
    if (level == n)
    {
        ans++;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (check(level, col))
        {
            // place the queen at (level, col) cell
            queens[level] = col;
            solve(level + 1);
            queens[level] = -1;
        }
    }
}

int main()
{
    fast
            cin >>
        n;
    queens.resize(n, -1);

    solve(0);
    cout << ans << endl;
}