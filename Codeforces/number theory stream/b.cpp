#include <bits/stdc++.h>
using namespace std;



void solve()
{
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }

    map<int, int> freq;
    for (int x : v)
    {
        freq[x % m]++;
    }

    
    for (auto &[a, r] : freq)
    {
        if (r >= k)
        {
            cout << "Yes\n";
            vector<int> ans;
            for (int x : v)
            {
                if (x % m == a)
                {
                    ans.push_back(x);
                    if (ans.size() == k)
                        break;
                }
            }
            for (auto y : ans)
            {
                cout << y << " ";
            }
            return;
        }
    }
    cout << "No\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}

