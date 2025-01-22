#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    int arr[n];

    int t = 1e6 + 1;
    vector<bool> isprime(t, true);
    isprime[0] = isprime[1] = false;
    set<int> st;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 2; i * i < t; i++)
    {
        if (!isprime[i])
            continue;
        for (int j = i + i; j < t; j += i)
        {
            isprime[j] = false;
        }
    }

    for (int i = 1; i < t; i++)
    {
        if (isprime[i])
        {
            st.insert(1ll * i * i);
        }
    }

    for (auto x : arr)
    {
        if (st.find(x) != st.end())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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
