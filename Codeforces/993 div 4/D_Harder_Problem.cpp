#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    int arr[n];
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }

    int ans[n] = {0};
    int num = n;
    for (int i = 0; i < n; i++)
    {

        if (mp[arr[i]] == 0)
        {

            ans[i] = arr[i];
            mp[arr[i]]++;
        }

        else
        {
            if (mp[num] == 0)
            {
                ans[i] = num;
            }
            else
            {

                while (mp[num] != 0)
                    num--;

                ans[i]=num;
            }

            mp[num]++;
            num--;
        }
    }

    for (auto &x : ans)
        cout << x << " ";
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