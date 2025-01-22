#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    int miniPosOdd = 1e4;
    int maxiNegOdd = -1e4;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            sum += arr[i];
            if (arr[i] % 2 and miniPosOdd > arr[i])
            {
                miniPosOdd = arr[i];
            }
        }
        else
        {
            if (arr[i] % 2 and maxiNegOdd < arr[i])
            {
                maxiNegOdd = arr[i];
            }
        }
    }

    if (sum % 2)
        cout << sum << endl;
    else
    {
        cout << sum- min(miniPosOdd, -maxiNegOdd);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}