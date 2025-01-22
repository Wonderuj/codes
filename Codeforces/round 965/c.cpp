#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;

    int stepX = (x + k - 1) / k;
    int stepY = (y + k - 1) / k;
    // cout << stepX << " " << stepY << " " << stepX - stepY << endl;

    cout<< stepX + stepY + abs(stepX - stepY) - (stepX > stepY) << endl;
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