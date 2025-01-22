#include <bits/stdc++.h>
using namespace std;
const int N = 4040;
bool g[N][N] = {false};
int indeg[N];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
        g[b][a] = true;
        indeg[a]++;
        indeg[b]++;
    }
    int res = 1e9 + 5;

    for (int i = 1; i <= n; i++)
    {

        for (int j = i + 1; j <= n; j++)
        {

            if (g[i][j])
            {

                for (int k = j + 1; k <= n; k++)
                {

                    if (g[i][k] && g[j][k])
                        res = min(res, indeg[i] + indeg[j] + indeg[k]);
                }
            }
        }
    }

    if (res == 1e9 + 5)
        cout << -1 << endl;
    else
        cout << res - 6 << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}