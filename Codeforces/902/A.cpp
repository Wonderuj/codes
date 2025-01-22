#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second < b.second;
}

void solve()
{
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> v(n, {0, 0});

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }

    sort(v.begin(), v.end(), comp);
    // for (auto x : v)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }

    long long sum = p;
    int people = n - 1;

    for (int i = 0; i < n and people > 0; i++)
    {

        if (p < v[i].second)
        {
            sum += 1LL * people * p;
            break;
        }

        if (people >= v[i].first)
        {
            sum += 1LL * v[i].second * v[i].first;
            people -= v[i].first;
        }
        else
        {
            sum += 1LL * people * v[i].second;
            break;
        }
    }

    cout << sum << endl;
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

/*
1
17 72217
1 1 1 1 1 1 1 1 1 1 1 23247 1 1 63392 1 1
72217 72217 57590 72217 47905 72217 72217 72217 29408 72217 72217 75144 72217 41359 96163 2366 72217
*/