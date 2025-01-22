#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    int res = 0;
    while (true)
    {
        int maxi=0;
        for(int i=0;i<n;i++){
            if(a[i]>=a[maxi]) maxi=i;
        }
        if (maxi == 0)
            break;
        ++res;
        ++a[0];
        --a[maxi];
    }
    cout << res << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}