#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int A = 0, B = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2)
        {
            int v= min(a[i-1]-a[i],k);
            a[i]+=v;
            k-=v;
            B+=a[i];
        }
        else
            A += a[i];

        
    }

    cout << A - B << endl;   //1 1 1 1
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

//14 6 3