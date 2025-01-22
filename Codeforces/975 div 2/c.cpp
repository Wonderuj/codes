#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ALL(x) x.begin(), x.end()

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (auto &x : a)
        cin >> x;

    int maxi = *max_element(ALL(a));

    int sum = accumulate(ALL(a), 0LL);

    int Y = sum + k;

    for (int s = n; s > 0; s--) // s is size of deck we are considering
    {
        int temp = (Y - (Y % s)); // number of cards s.d, should be a largest multiple of s so we can divide it in d decks

        if (temp >= sum and temp >= (maxi * s)) // # of cards should be minimum x and maxi should be at most = to number of decks (d)
        {
            cout << s << endl;
            return;
        }
    }
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