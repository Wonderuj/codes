#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    int z = k + n - 1;
    int a = (z + k)/2;
    int sumN = z * (z + 1);
    int sumK = k * (k - 1);
    int sumx = a * (a + 1);
    int sumy = (a + 1) * (a + 2);
    cout << min(abs(sumN - (sumx)) / (2 * 1LL), abs(sumN - (sumy)) / (2 * 1LL));
    cout << endl;
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