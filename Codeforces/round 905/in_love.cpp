#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    multiset<int> ll, rr;

    for (int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        int l, r;
        if (x == '+')
        {
            cin >> l >> r;
            ll.insert(l);
            rr.insert(r);
        }
        else
        {
            cin >> l >> r;
            ll.erase(ll.find(l));
            rr.erase(rr.find(r));
        }
        if (ll.size() <= 1)
        {
            cout << "NO\n";
            continue;
        }

        // if (*ll.rbegin() > *rr.begin())
        // { // if the maximum left boundary is greater than minimum right boundary then we have a disjoint pair
        //     cout << "YES\n";
        // }
        // else
        //     cout << "NO\n";
        cout << ((*ll.rbegin() > *rr.begin()) ? "YES\n":"NO\n");
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