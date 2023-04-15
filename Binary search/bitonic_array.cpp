#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,X;
int check(int arr[], int x)
{
    if (x == n - 1)
    {
        return 1;
    }
    else
    {
        return arr[x] > arr[x + 1];
    }
}
int check2(int arr[],int x)
{
    if (arr[x] < X)
        return 0;
    else
        return 1;
}
void solve()
{
    int arr[100100];
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int lo=0;
    int hi=n-1;
    int ans= n;
    while(lo<=hi){
        int mid = (lo + hi) / 2;
        if(check(arr,mid)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    //cout<<ans<<'\n';
   while(lo<=ans){

   }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}