#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin >> n;
    int brr[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> brr[i];
    }
    vector<int> arr(n, 0);
    for (int i = 0; i < n - 2; i++)
    {
        arr[i + 1] = brr[i] | brr[i + 1];
    }


   
    arr[0] = brr[0] ;

    arr[n - 1] = brr[n - 2] ;

    // cout<<endl;

    for(int i=0;i<n-1;i++){
        if((arr[i]&arr[i+1])!=brr[i]){
            
            cout<<"-1\n";
            return;
        }
    }
    // for(auto x:brr){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    for (auto x : arr)
    {
        cout << x << " ";
    }

    cout<<'\n';
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