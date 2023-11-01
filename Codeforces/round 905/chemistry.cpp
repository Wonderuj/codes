#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int alpha[26];
    memset(alpha, 0, sizeof(alpha));

    for (int i = 0; i < n; i++)
    {
        int x = s[i] - 'a';
        alpha[x]++;
    }

    int even = 0, odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] != 0)
        {
            alpha[i] % 2 == 0 ? even++ : odd++;
        }
    }

    if(k>=odd){
        k-=odd;
        odd=0;
    }
    else{
        odd-=k;
    }
    if(odd<2) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
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