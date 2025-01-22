#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    
    if(abs(a-b)%2){
        cout<<"NO\n";
    }
    else cout<<"YES\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}