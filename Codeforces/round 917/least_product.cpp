#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int neg = 0, zero = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0)
        {
            neg++;
        }
        else if (arr[i] == 0)
            zero ++;
    }

    if (zero || neg%2)
    {
        cout << 0 << '\n';
        return;
    }

    else if (neg%2==0){ //multiplication will come out positive since even number of negatives
        cout<<1<<'\n';
        bool flag=1;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                cout<<i+1<<" "<<0<<'\n';
                flag=0;
                break;
            }
        }
        if(flag) cout<<1<<" "<<0<<'\n';
    }   
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