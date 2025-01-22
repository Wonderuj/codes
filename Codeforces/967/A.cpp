#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[101] ;
    memset(arr,0,sizeof(arr));

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[x]++;
    }
    int maxi = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (arr[i] > arr[maxi])
        {
            maxi = i;
        }

    }
    cout<<n-arr[maxi]<<endl;
    // cout<<maxi<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}

/*
1
6
1 1 4 5 1 4
*/