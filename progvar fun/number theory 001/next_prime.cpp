#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n = 1e5 + 7;
    vector<bool> isprime(n, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i < n; i++)
    {
        if (!isprime[i])
            continue;
        for (int j = i + i; j < n; j += i)
        {
            isprime[j] = false;
        }
    }
    int x;
    cin>>x;
    if(isprime[x]) cout<<x<<"\n";
    else{
        int i=x;
        while(!isprime[i]){
            i++;
        }
        cout<<i<<"\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}