#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, m;
int arr[55][11];
int dp[55][(1 << 11)];

int rec(int level, int mask)
{ // iterating level over students
    if (level == m)
        return 0;

    if (dp[level][mask] != -1)
        return dp[level][mask];

    int ans = rec(level + 1, mask);

    for (int rank = 0; rank < n; rank++)
    {
        if ((mask & (1 << rank)) == 0)
        {
            ans = max(ans, rec(level + 1, mask|(1<<rank))+arr[level][rank]);
        }
    }

    return dp[level][mask] =ans;
}

void solve()
{
    // n is number of ranks, m is number of students
    cin >> n >> m;

    for (int i = 0; i < m; i++) // for each student, I have been given data of nth rank
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << rec(0, 0) << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}

/*Description

There are N Ranks and M students in a class. Each student has a happiness value for the rank in the class he gets. 
The i th Student gets happy[i][j] on getting a rank j. It's ok to not keep all students in the ranks (They get 0 happiness). 
At most one student can be assigned to a rank. The total happiness of the assignment can be calculated as Sum of Happiness of each of the students in the class. 
Find the best way to calculate.

Input Format
The first line contains an integer T (1 ≤ T ≤ 200) - the number of testcases.
The first line of each test case contains two space-separated integers N, M. 1 ≤ N ≤ 10, 1 ≤ M ≤ 50.
The next M lines contain N integers, 0 ≤ happy[i][j] ≤ 10^5.

Output Format
For each test case print the maximum sum of happiness possible in a new line.


Sample Input 1

4
6 11
49 78 23 100 29 2
11 28 39 27 77 45
24 52 18 45 84 41
85 88 75 21 98 100
59 24 27 21 94 90
88 0 0 16 89 54
63 24 100 23 18 75
26 34 54 14 28 11
68 61 40 14 67 14
16 62 17 70 29 52
97 53 0 98 90 75
1 2
8
6
5 9
6 0 7 9 3
10 0 1 1 4
0 2 4 6 1
7 1 5 5 10
0 3 3 1 10
9 8 6 9 1
0 10 6 0 2
4 9 2 4 9
4 10 10 3 7
4 5
10 2 4 0
10 1 6 7
6 3 2 0
2 3 5 1
10 4 7 6

Sample Output 1

564
8
49
27
*/