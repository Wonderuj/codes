#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int arr[5] = {0};
    for (int i = 0; i < 5; i++)
    {
        if (i == 2)
            continue;
        cin >> arr[i];
    }

    int ans=0,cnt=0;
    arr[2] = arr[0] + arr[1];
    for (int i = 0; i < 3; i++)
    {
        if (arr[i + 2] == arr[i] + arr[i + 1])
        {
            cnt++;
        }
    }
    ans=max(ans,cnt);
    cnt=0;
    arr[2] = arr[3] - arr[1];
    for (int i = 0; i < 3; i++)
    {
        if (arr[i + 2] == arr[i] + arr[i + 1])
        {
            cnt++;
        }
    }
    ans = max(ans, cnt);
    cnt=0;
    arr[2] = arr[4] - arr[3];
    for (int i = 0; i < 3; i++)
    {
        if (arr[i + 2] == arr[i] + arr[i + 1])
        {
            cnt++;
        }
    }
    ans = max(ans, cnt);
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}