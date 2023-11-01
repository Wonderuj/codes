// #include <bits/stdc++.h>
// using namespace std;
// int n; // X is element to be compared or found
// int arr[100100];
// int check(int x)
// {
//     if (arr[x] < arr[0])
//         return 1;
//     else
//         return 0;
// }

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int lo = 0;
//     int hi = n - 1;
//     int ans = n;
//     while (lo <= hi)
//     {
//         int mid = (lo + hi) / 2;
//         if (check(mid))
//         {
//             ans = mid;
//             hi = mid - 1;
//         }
//         else
//         {
//             lo = mid + 1;
//         }
//     }
//     cout << ans << endl;
// }


//to find how many times the array has been rotated
#include <bits/stdc++.h>
using namespace std;

int check(int arr[], int x)
{
    if (arr[x] < arr[0])
        return 1;
    else
        return 0;
}

void solve()
{
    int n; 
    int arr[100100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int lo = 0;
    int hi = n - 1;
    int ans = n;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(arr,mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << n-ans << endl;
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