#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int t = 100100;
    vector<bool> isprime(t, true);

    for (int i = 2; i * i < t; i++)
    {
        if (!isprime[i])
            continue;
        for (int j = i + i; j < t; j += i)
        {
            isprime[j] = false;
        }
    }
    
    //if x is prime then its coloured 1 otherwise 2
    if(n<3){
        cout<<"1\n";
    }
    else cout<<"2\n";

    for(int i=1;i<=n;i++){
        if(isprime[i+1])  
            cout<<"1 ";
        else cout<<"2 ";
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