#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int r, c;
    cin >> r >> c;

    if (r == 1 and c == 1)
    {

        cout << 0 << endl;
        return;
    }

    vector<int> rows, cols;
    if (c == 1)
    {
        cols.push_back(1);

        for (int i = 2; rows.size() < r; i++)
        {
            rows.push_back(i);
        }
    }
    else
    {
        int i = 1;
        for (; rows.size() < r; i++)
        {
            rows.push_back(i);
        }
        for (; cols.size() < c; i++)
        {
            cols.push_back(i);
        }
    }

    vector<vector<int>> ans(r, vector<int>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ans[i][j] = rows[i] * cols[j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
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