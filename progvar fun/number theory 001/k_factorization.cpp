#include <bits/stdc++.h>
using namespace std;

#define int long long
int smallestPrime[100100];

vector<int> primeF(int x)
{
    vector<int> ans;
    while (x > 1)
    {
        ans.push_back(smallestPrime[x]);
        x /= smallestPrime[x];
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> divisors;
    for (int i = 2; i <= n; i++)
    {
        smallestPrime[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (smallestPrime[i] == i)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                if (smallestPrime[j] == j)
                {
                    smallestPrime[j] = i;
                }
            }
        }
    }

    vector<int> ans = primeF(n);

    if(ans.size()<k){
        cout<<"-1\n";
        return;
    }
    else{
        
        for(int i=0;i<k-1;i++){
            cout<<ans[i]<<" ";
        }
        int pro=1;
        for(int i=k-1;i<ans.size();i++){
            pro*=ans[i];
        }
        cout<<pro<<endl;
        
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