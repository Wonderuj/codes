#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int t = 1000100;
    vector<bool> isprime(t, true);
    isprime[1] = false;

    for (int i = 2; i * i < t; i++)
    {
        if (!isprime[i])
            continue;
        for (int j = i + i; j < t; j += i)
        {
            isprime[j] = false;
        }
    }
    int cnt = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = i; j <= n; j *= i)
            {
                cnt++;
                v.push_back(j);
            }
        }
    }

    cout<<cnt<<endl;
    for(auto x:v){
        cout<<x<<" ";
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