#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n, k;
    cin >> n>> k;

    int ans = 0;
    int min = n - (k - 1);

   ans=(n*(n+1)/2)-((min-1)*(min)/2);

    
    if (ans % 2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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