//return the index of max point of bitonic array

// #include<bits/stdc++.h>
// using namespace std;
// int arr[100100];
// int n;
// bool check(int x){
//     if(x==n-1) return 1;
//     else return arr[x]>arr[x+1];
// }
// void solve(){
//     cin>>n;
  
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int hi=n-1, lo=0;
//     int ans=n;
//     while(lo<=hi){
//         int mid=(lo+hi)/2;
//         if(check(mid)){
//             ans=mid;
//             hi=mid-1;
//         }
//         else{
//             lo=mid+1;
//         }
//     }

//     cout<<ans<<endl;
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }


//we can also make it so that monotone space is like 1 1 1 1 0 0 0  and we need last 1:
#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int n;
bool check(int x)
{
    if (x == 0)
        return 1;
    else
        return arr[x] > arr[x - 1];
}
void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int hi = n - 1, lo = 0;
    int ans = n;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;   //find if theres another 1 on right side part of it
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}