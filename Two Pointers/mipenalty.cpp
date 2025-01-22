#include <bits/stdc++.h>
using namespace std;
int distinct = 0;
int freq[1000050];

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int tail = 0, head = -1;
    int ans = k;
    while (tail < n - k + 1)
    {
        while ((head + 1) < n && ((head - tail + 1) < k))
        {
            head++;
            if (freq[arr[head]] == 0)
            {
                distinct++;
            }
            freq[arr[head]]++;
        }
        ans = min(ans, distinct);

        if (head >= tail)
        {
            freq[arr[tail]]--;
            if (freq[arr[tail]] == 0)
            {
                distinct--;
            }
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
    }
    cout << ans << '\n';
    distinct = 0;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int freq[1000100];
// void solve()
// {
//     int n, d;
//     cin>>n>>d;
//     int v[n];
   

//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i];
//         freq[v[i]] = 0;
//     }

//     int cnt = 0;
//     int ans = d;
//     int head = -1, tail = 0;

//     while (tail < n - d + 1)
//     {
//         while ((head + 1 < n) && (head - tail + 1) < d)
//         {
//             head++;
//             freq[v[head]]++;
//             if (freq[v[head]] == 1)
//             {
//                 cnt++;
//             }
//         }
//         ans = min(cnt, ans);
//         // cout<<head<< " head- tail "<<tail;
//         // cout<<endl<<ans<<" ans- cnt "<<cnt<<endl;

//         if (head - tail + 1 >= d)
//         {
//             freq[v[tail]]--;
//             if (freq[v[tail]] == 0)
//             {
//                 cnt--;
//             }
//             tail++;
//         }
//     }
//     cout << ans << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int _t;
//     cin >> _t;
//     while (_t--)
//         solve();
// }