#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int x, y;
    int ans = 0;
    cin >> x >> y;
    while(y>x){
        if(y%2){   //checking if its an odd number, if it is then y++ vala move
            y++;
            ans++;
        }                               //complexity - O(log y) 
        y/=2;
        ans++;
    }
    ans+=(x-y);       //either vo x pe phouch gaya hoga to 0 add hoga vrna y < x vala case aa jayaga to Y+1 karna padega X tk phouchne ke lia and that is x-y steps.
    cout<<ans<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}