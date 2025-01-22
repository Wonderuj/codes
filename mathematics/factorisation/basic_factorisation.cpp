#include <bits/stdc++.h>
using namespace std;
#define int long long
using ii = pair<int, int>;

vector<ii> primefactor(int x)
{
    vector<ii> v;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                cnt++;
                x /= i;
            }
            v.push_back({i, cnt});
        }
    }
    if (x > 1)
    {
        v.push_back({x, 1});
    }
    return v;
}

void solve()
{
    int n;
    cin >> n;
    vector<ii> ans;
    ans = primefactor(n);
    for (auto v : ans)
    {
        cout << v.first << " " << v.second << endl;
    }
    cout << "done\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}