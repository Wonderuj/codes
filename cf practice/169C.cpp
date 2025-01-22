#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    int prefix[n + 2]; // 0th index and n+1th index are for partial and prefix sum implementation
    memset(prefix, 0, sizeof(prefix));

    // taking the input
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l, r;

    // building up the partial sum
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        prefix[l] += 1;
        prefix[r + 1] -= 1;
    }

    // prefix sum of partial sum
    for (int i = 1; i <= n; i++)
    {
        prefix[i] += prefix[i - 1];
    }

    // for(auto x: prefix){
    //     cout<<x<<" ";
    // }
    sort(arr, arr + n, greater<int>());
    sort(prefix+1,prefix+n+1,greater<int>());
    // priority_queue<int> qq;
    // for (int i = 1; i <= n; i++)
    // {
    //     qq.push(prefix[i]);
    // }

    // for(auto x:arr){
    //     cout<<x<<" ";
    // }
    // int i = 0, sum = 0;
    // while (!qq.empty())
    // {
    //     int x = qq.top();
    //     qq.pop();
    //     sum += 1LL * x * arr[i];
    //     i++;
    // }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=1LL*prefix[i+1]*arr[i];
    }
    cout << sum << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}