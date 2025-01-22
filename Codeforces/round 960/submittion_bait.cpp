#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end(), greater<int>());
   
    int x = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < x)
        {
            if (i % 2 == 0)
            {
                cout << "NO\n";
                return;
            }
            else
            {
                cout << "YES\n";
                return;
            }
        }
    }
    
    if (n % 2 == 1)
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
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