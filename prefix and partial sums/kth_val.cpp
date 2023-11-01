// https://www.youtube.com/watch?v=F43IOF2MJKo

#include <bits/stdc++.h>
using namespace std;
#define int long long
//Binary search
int bs(vector<pair<int, int>> &v, int k)
{
    int n = v.size();
    int lo = 0, hi = n - 1;
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (v[mid].second >= k)
        {
            ans = v[mid].first;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    int arr[n + 1];
    int prefix[n + 2];  //0th index and n+1th index are for partial and prefix sum implementation
    memset(prefix, 0, sizeof(prefix));

    //taking the input
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int l, r;

    //building up the partial sum
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        prefix[l] += 1;
        prefix[r + 1] -= 1;
    }

    //prefix sum of partial sum
    for (int i = 1; i <= n; i++)
    {
        prefix[i] += prefix[i - 1];
    }

    //vector to store how many times the number occured in range
    vector<pair<int, int>> v;
    
    for (int i = 1; i <= n; i++)
    {
        v.push_back({arr[i], prefix[i]});
    }   

    sort(v.begin(), v.end());

    int nn = v.size();

    //prefix sum 
    for (int i = 1; i < nn; i++)
    {
        v[i].second += v[i - 1].second;
    }

    int k;
    while (q--)
    {
        cin >> k;
        int ans = bs(v, k); //binary search to find the index which came at kth position
        cout << ans << " ";
    }
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