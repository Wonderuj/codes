#include <bits/stdc++.h>
using namespace std;
#define int long long


// Solve here
int phi[1000100];

void solve()
{
    int n;
    cin >> n;
    int ans = n;
    for (int i = 2; i * i <= n; i++)
        phi[i] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (phi[i] == 1)
        {
            for (int j = i * i; j * j <= n; j += i)
            {
                phi[j] = 0;
            }
            if (n % i == 0)
            {
                while (n % i == 0)
                    n /= i;
                ans -= ans / i;
            }
        }
    }
    if (n > 1)
    {
        ans -= ans / n;
    }
    cout << ans << "\n";
}
signed main()
{
    // Fast IO
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Number of test cases
    int t = 1;
    // Comment if number of test case is 1
    //  cin>>t;
    while (t--)
    {
        // Call the Solve
        solve();
    }
}