#include <bits/stdc++.h>
using namespace std;
int N = 200200;

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    map<int, int> mp,cp;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }

    int cnt=0;
    
    while(1){
        if(mp[cnt]){
            mp[cnt]--;
            cp[cnt%x]+=mp[cnt];
            cnt++;
        }
        else if(cp[cnt%x]){
            cp[cnt%x]--;
            cnt++;
        }
        else{
            cout<<cnt<<endl;
            return;
        }

    }

    
    // x=7 i=6 and mp[1]>2.... 
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