#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    int maxi = -1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    for (int m = 0; m < 3; m++)
                    {
                        arr[i] += 1;
                        arr[j] += 1;
                        arr[k] += 1;
                        arr[l] += 1;
                        arr[m] += 1;
                        
                        maxi = max(maxi, arr[0] * arr[1] * arr[2]);
                        
                        arr[i] -= 1;
                        arr[j] -= 1;
                        arr[k] -= 1;
                        arr[l] -= 1;
                        arr[m] -= 1;
                    }
                }
            }
        }
    }
    cout << maxi << '\n';
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