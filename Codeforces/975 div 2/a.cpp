// https://www.youtube.com/watch?v=2M5S9QNetg4

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr)
        cin >> x;

    int maxiA = 0, maxiB = 0, cntA = 0, cntB = 0;

    for (int i = 0; i < n; i += 2)
    {
        cntA++;
        maxiA=max(maxiA, arr[i]);
    }

    for (int i = 1; i < n; i += 2)
    {
        cntB++;
        maxiB = max(maxiB, arr[i]);
    }

    cout<<max(maxiA+cntA, maxiB+cntB)<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}