#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l, r, L, R;
    cin >> l >> r >> L >> R;

    if (L < l)
    { // one which is starting first is l
        swap(l, L);
        swap(r, R);
    }

    if (L > r)
    { // No intersection
        cout << 1 << endl;
        return;
    }

    int gate = 0;
    for (int i = L; (i < r) & (i < R); i++)
    { //Looping till reaching either or the end
        gate++;
    }
    if (l < L)
        gate++;
    if (r != R)
        gate++;
    cout << gate << endl;
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