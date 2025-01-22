#include <bits/stdc++.h>
using namespace std;

void solve()
{
    set<int> s;
    int n;
    cin >> n;
    int arr[n];
    for (int i =0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    s.erase(s.begin());
    if(s.empty()){
        cout<<"-1\n";
    }
    else{
        cout<<*s.begin()<<'\n';
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}