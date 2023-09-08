#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll l, r;  //range l to r
    cin >> l >> r;
    ll rt = 0;

    //finding sqrt r
    for (ll i = 1; i * i <= r; i++)
    {
        rt++;
    }
    // cout<<rt;

    vector<ll> isprime(rt + 1, 1);
    vector<ll> primes;

    //sieve from 1 to sqrt(r)
    for (ll i = 2; i <= rt; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j <= rt; j += i)
            {
                isprime[j] = 0;
            }
        }
    }

    // for (auto v : primes)
    // {
    //     cout << v << ' ';
    // }
    isprime.assign(r - l + 1, 1);

//using those primes to sieve the range l to r
    for (auto i : primes)
    {
        ll curMul = ((l + i - 1) / i) * i;   //nearest multiple from l
        while (curMul <= r)
        {
            if (curMul != i)
            {
                isprime[curMul - l] = 0;
            }
            curMul += i;
        }
    }
    
    vector<ll>ans;
    for(ll i=0;i<r-l+1;i++){
        if(isprime[i]){
            if(i+l!=1)
                ans.push_back(l+i);
        }
    }

    cout<<ans.size()<<'\n';
    for(auto v:ans){
        cout<<v<<" ";
    }
    cout<<'\n';
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}