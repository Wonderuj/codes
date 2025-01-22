#include <bits/stdc++.h>
using namespace std;
char arr[8][8];
vector<int> queens;
bool check(int row, int col)
{
    if (arr[row][col] == '*')
    {
        return 0;
    }
    for (int prow = 0; prow < row; prow++)
    {
        int pcol = queens[prow];
        if (pcol == col || abs(row - prow) == abs(col - pcol))
        {
            return 0;
        }
    }
    return 1;
}
int cnt = 0;

void rec(int level)
{
    // base case
    if (level == 8)
    {
        cnt++;
    }
    // recursive case
    for (int col = 0; col < 8; col++)
    {
        if (check(level, col))
        {
            // place/move
            queens.push_back(col);
            rec(level + 1);
            queens.pop_back();
        }
    }
}
void solve()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> arr[i][j];
        }
    }
    rec(0);
    cout << cnt << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}

// // vector<vector <int>> arr(n);   for vector input
// // for (int i = 0; i < n; i++)
// // {
// //    arr[i].resize(n);
// //    for (int j = 0; j < n; j++)
// //    {
// //     cin >> arr[i][j];
// //    }
// // }

// #include <bits/stdc++.h>
// using namespace std;

// char arr[8][8];
// vector<int> queens;
// int cnt = 0;

// bool check(int row, int col)
// {
//     for (int prow = 0; prow < row; prow++)
//     {
//         int pcol = queens[prow];
//         if (pcol == col || abs(row - prow) == abs(col - pcol) || arr[row][col] == '*') 
//         {
//             return false;
//         }
//     }
//     return true;
// }

// void rec(int level)
// {
//     // base case
//     if (level == 8)
//     {
//         cnt++;
//         return;
//     }
//     // recursive case
//     for (int col = 0; col < 8; col++)
//     {
//         if (check(level, col))
//         {
//             // place/move
//             queens.push_back(col);
//             rec(level + 1);
//             queens.pop_back();
//         }
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     for (int i = 0; i < 8; i++)
//     {
//         for (int j = 0; j < 8; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }

//     rec(0);
//     cout << cnt << endl;
//     return 0;
// }
