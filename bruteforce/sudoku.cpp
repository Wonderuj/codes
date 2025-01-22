#include <bits/stdc++.h>
using namespace std;
const int bs = 4;  // board size
const int ces = 2; // cell size
int board[bs][bs];

/*
0 1 0 0
0 0 4 0
0 4 0 0
0 0 3 0 
*/
bool check(int ch, int row, int col)
{
    // check in row
    for (int c = 0; c < bs; c++)
    {
        if (c != col && board[row][c] == ch)
        {
            return false;
        }
    }

    // check in col
    for (int r = 0; r < bs; r++)
    {
        if (r != row && board[r][col] == ch)
        {
            return false;
        }
    }

    // check in square
    int str = (row / ces) * ces;
    int stc = (col / ces) * ces;
    for (int dx = 0; dx < ces; dx++)
    {
        for (int dy = 0; dy < ces; dy++)
        {
            if (str+dx==row && stc+dy==col) continue;  //we wont check the cell with itself
            if(board[str+dx][stc+dy]==ch){
                return false;
            }                //we are checking all the cells except for the same cell in the square if it contains our ch value or not
        }
    }
    return true;
}
int ans=0;
void rec(int row, int col)
{ // here level is cell

    if(col==bs){
        rec(row+1,0);
        return;
    }
    // base case
    if (row==bs)
    {
        //
        ans++;
        cout<<"Answer "<<ans<<endl;
        for (int i = 0; i < bs; i++)
        {
            for (int j = 0; j < bs; j++)
            {
                cout << board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    if (board[row][col] == 0)
    { // we can place an element
        for (int ch = 1; ch <= bs; ch++)
        { // ch is choice of numbers that we can place on board. It is from 1 to 4 thaat is ch=1 to ch= bs
            if (check(ch, row, col))
            {
                board[row][col] = ch;
                rec(row, col + 1);
                board[row][col] = 0;
            }
        }
    }
    else
    { // pre-filled board i.e. cell already have some number
        if (check(board[row][col], row, col))
        {
            rec(row, col + 1);
        }
    }
}
void solve()
{
    for (int i = 0; i < bs; i++)
    {
        for (int j = 0; j < bs; j++)
        {
            cin >> board[i][j];
        }
    }
    rec(0,0);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}

//there is solution using bit masking which I havent done
