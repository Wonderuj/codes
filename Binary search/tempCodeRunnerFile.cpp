#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, k;
int arr[100100];
int p[100100];
int numzero(int l,int r){
    int ans =(r-l+1) -(p[r]-(l>0?p[l-1]:0));
}
bool check(int st, int x)
{
    return numzero(st,x)<= k;
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        p[i] = arr[i];
        if (i)
            p[i] += p[i - 1];
    }
    int total = 0;
    for (int st = 0; st < n; st++)
    {
        int lo = st;
        int hi = n - 1;
        int ans = 0;
        while (lo <= hi)
        {
            int mid = (hi + lo) / 2;
            if (check(st, mid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        total = max(total,ans-st+1);
    }
    cout << total << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}