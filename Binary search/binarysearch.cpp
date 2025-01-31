// Basic Tempelate
#include<bits/stdc++.h>
using namespace std;
int n; int arr[100100];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int lo=0;
    int hi=n-1;
    int ans=-1;
    while (lo<=hi)   
    {
        int mid= (lo+hi)/2;
        if(arr[mid]==1){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
}

//------------------------------------------------------

//These both code below have O(log N) time complexity
//Lower Bound from this :

// #include <bits/stdc++.h>
//     using namespace std;
// int n,X;                    //X is element to be compared or found
// int arr[100100];
// int check (int x){
//     if(arr[x]<X) return 0;
//     else return 1;
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
//     cin>> X;
//     int lo = 0;
//     int hi = n - 1;
//     int ans = -1;
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

// //------------------------------------------------------
// // Upper Bound from this :

// #include <bits/stdc++.h>
// using namespace std;
// int n, X; // X is element to be compared or found
// int arr[100100];
// int check(int x)
// {
//     if (arr[x] <= X)            //or if (arr[x]> X) return 1; else return 0;
//         return 0;
//     else
//         return 1;
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
//     cin >> X;
//     int lo = 0;
//     int hi = n - 1;
//     int ans = -1;
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
