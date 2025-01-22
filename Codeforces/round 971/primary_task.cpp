#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    if((n>=102 and n<=109) or (n>=1010 and n<=1099) ) cout<<"YES\n";
    else cout<<"NO\n";
    
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