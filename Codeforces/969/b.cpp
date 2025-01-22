#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto &x : arr)
    {
        cin >> x;
    }

    int maxi = *max_element(arr.begin(), arr.end());
    while (m--)
    {
        char c;
        int l, r;
        cin >> c>> l >> r;
        if (maxi <= r and maxi >= l)
        {
            if (c == '+')
            {
                maxi++;
            }
            else
                maxi--;
        }
        cout << maxi << endl;
    }
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