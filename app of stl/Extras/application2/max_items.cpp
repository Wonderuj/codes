//Shop have n items, ith item have price of Pi..We have budget constraint of B. Find max number of items you can buy.

// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     sort(arr,arr+n);  //order is O(NlogN)  , it is called itro sort
//     int m;
//     cin>>m;
//     while (m--){
//         int b;
//         cin >> b;
//         int ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (arr[i] <= b)
//             {
//                 ans++;
//                 b -= arr[i];
//             }
//             else
//             {
//                 break;
//             }
//         }
//         cout << ans << '\n';
//     }
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }
// complexity - O(N log N + M.N)
//--------------------------------------------------------------------------------------
// Optimizing the solution.. using Prefix Sums.

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v){
        cin>>i;
    }
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++){        //prefix sum
        v[i]+=v[i-1];
    }
    int m;
    cin>>m;
    while(m--){
        int b;
        cin>>b;
        cout<< upper_bound(v.begin(),v.end(),b)-v.begin();   //number of elements<x where x is number just greater than our budget.
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}

//complexity - O(N log N + M.log N)
// for a constraint like M,N <= 10^5 and ai,bi<=10^9 the code with prefix sum will pass but top code will not because of M.N term.
