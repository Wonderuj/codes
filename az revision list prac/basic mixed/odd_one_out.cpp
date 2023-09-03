// You are given an array of N integers.The frequency of exactly one integer is odd.Find that integer.

//     Input Format

//         The first line of the input contains one integer T -
//     the number of test cases.Then T test cases follow.

//     The first line of each test case contains one integer N -
//     the length of the array.

//     The second line of each test case contains N space -
//     separated integers.

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1001000];

void solve()
{
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ans ^= arr[i];
    }

    cout
        << ans << '\n';
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