#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    // finding number of subarray with length >1 element is a part of.

    map<int, int> mp; // map<key,value> stores number of subarray as key and, number of points which lie in exactly key number of segments

    for (int i = 0; i < n; i++)
    {

        int temp = (i + 1) * (n - i) - 1;
        mp[temp]++;

        // to find the same for number of points lying between them
        if (i > 0)
        { // starting with points b/w index 1 and index 0
            int temp2= i*(n-i);
            mp[temp2]+=(v[i]-v[i-1]-1);
            //number of integer points b/w l and r is r-l-1
        }
    }

    while(q--){
        int k;
        cin>>k;
        // cout<<mp[k]<<endl;
        if(mp.find(k)==mp.end()) cout<<0<<" ";
        else cout<<mp[k]<<" ";
    }
    cout<<endl; 
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}