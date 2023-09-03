// https://www.youtube.com/watch?v=Lrp9v-NQPXw

// Time Complexity - O(N Log N) when used priority queue and O(n) when used maxi variable, Space Complexity - O(N)

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// void solve()
// {
//     int n;
//     cin >> n;
//     int arr[n], left[n], right[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     // priority_queue<int> pq;
//     // pq.push(0);
//     // for (int i = 0; i < n; i++)
//     // {
//     //     left[i] = pq.top();
//     //     pq.push(arr[i]);
//     // }
//     // while (!pq.empty())
//     // {
//     //     pq.pop();
//     // }
//     // pq.push(0);
//     // for (int i = n - 1; i > 0; i--)
//     // {
//     //     right[i] = pq.top();
//     //     pq.push(arr[i]);
//     // }

//     int maxi=-1e9;
//     for(int i=0;i<n;i++){
//         maxi=max(maxi, arr[i]);
//         left[i]=maxi;
//     }
//     maxi=-1e9;
//     for(int i=n-1;i>0;i--){
//         maxi = max(maxi, arr[i]);
//         right[i] = maxi;
//     }


//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int temp = min(left[i], right[i]) - arr[i];
//         if (temp > 0)
//         {
//             ans += temp;
//         }
//     }
//     cout << ans << '\n';
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

#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int left=0;
    int right =n-1;
    int ans=0;
    int leftbar=arr[0]; int rightbar=arr[n-1];
    while(left<=right){
        if(leftbar<rightbar){
            if(arr[left]>leftbar){
                leftbar=arr[left];
            }
            else{
                ans+=leftbar-arr[left];
                left++;
            }
        }
        else{
            if(arr[right]>rightbar){
                rightbar=arr[right];
            }
            else{
                ans+=rightbar-arr[right];
                right--;
            }
        }
    }
    cout<<ans<<'\n';
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