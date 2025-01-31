/*Description

There are n cities and m roads between them.
Your task is to process q queries where you have to determine the length of the shortest route between two given cities.

Input Format

The first input line has three integers n, m and q: the number of cities, roads, and queries.
Then, there are m lines describing the roads. Each line has three integers a, b and c: 
there is a road between cities a and b whose length is c. All roads are two-way roads.
Finally, there are q lines describing the queries. Each line has two integers a and b: 
Determine the length of the shortest route between cities a and b.

Output Format

Print the length of the shortest route for each query. If there is no route, print −1 instead.


Constraints

1 ≤ n ≤ 500
1 ≤ m ≤ n^2
1 ≤ q ≤ 10^5
1 ≤ a, b ≤ n
1 ≤ c ≤ 10^9
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
int dist[505][505];
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                dist[i][j] = 1e18;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == 1e18)
        {
            cout << "-1\n";
        }
        else
        {
            cout << dist[a][b] << '\n';
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