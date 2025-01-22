#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
vector<int> g[N];
int deg[N];

void solve()
{
    cin >> n >> m;

    if (m > n)
    {
        printf("unknown topology\n");
        return;
    }

    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        deg[a]++;
        deg[b]++;
    }

    if (m == n)
    {
        bool flag = true;
        for (int i = 1; i <= n; i++)
            if (deg[i] != 2)
            {
                cout << "unknown topology\n";
                return;
            }

        cout << ("ring topology\n");
        return;
    }

    else
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 1)
                cnt++;
        if (cnt == 2)
        {
            cout << "bus topology\n";
        }
        else if (cnt == n - 1)
        {
            cout << "star topology\n";
        }
        else
        {
            cout << "unknown topology\n";
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