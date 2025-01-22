#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (!is_sorted(v.begin(), v.end()))
    {
        cout << "0\n";
        return;
    }

    int mini = 1e9;
    for (int i = 0; i < n - 1; i++)
    {
        int diff = abs(v[i] - v[i + 1]);
        if (diff < mini)
        {
            mini = diff;
        }
    }
    cout << mini / 2 + 1 << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    while (_t--)
        solve();
}



