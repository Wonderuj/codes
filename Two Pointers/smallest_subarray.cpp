#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int arr[100100];
    set<int> s;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    int len = 0;
    int x = s.size();
    int ans = INT_MAX;
    int tail = 0, head = -1;

    while (tail < n)
    {
        while (head + 1 < n && mp.size() < x)
        {
            head++;
            mp[arr[head]]++;
        }
        len = head - tail + 1;
        if (mp.size() == x)
        {
            ans = min(len, ans);
        }
        // cout<<tail<<" tail-head  "<<head<<endl;  

        if (head >= tail)
        {
            mp[arr[tail]]--;
            if (mp[arr[tail]]==0)
                mp.erase(arr[tail]);

            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
    }
    cout << ans << endl;
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