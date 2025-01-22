#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int dx[] = {a, a, b, -b, -a, -a, b, -b};
    int dy[] = {b, -b, a, a, b, -b, -a, -a};

    pair<int, int> king, queen;
    cin >> king.first >> king.second;
    cin >> queen.first >> queen.second;
    set<pair<int, int>> st1, st2;

    for (int i = 0; i < 8; i++)
    {
        int x = king.first + dx[i];
        int y = king.second + dy[i];
        st1.insert({x, y});
    }

    for (int i = 0; i < 8; i++)
    {
        int x = queen.first + dx[i];
        int y = queen.second + dy[i];
        st2.insert({x, y});
    }
    int cnt = 0;

    for (auto &x : st1)
    {
        if (st2.find(x) != st2.end())
        {
            cnt++;
        }
    }

    cout << cnt << '\n';
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


//Q)   Two permutations Pinely round 1

// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n, a, b;
//     cin>>n>>a>>b;
//     if (n == 1)
//     {
//         cout << "YES\n";
//         return;
//     }

//     if (n - (a + b) >= 2 or (a==b and b==n) )
//     {
//         cout << "YES\n";
//         return;
//     }
//     cout << "NO\n";
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int _t;
//     cin >> _t;
//     while (_t--)
//         solve();
// }