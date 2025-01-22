// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n; cin>>n;
//     list<pair<string,int>>li;
//     while(n--){
//         string x; int y;
//         cin>>x>>y;
//         li.push_back(make_pair(x,y));
//     }
//     li.sort();
//     for (auto itr = li.begin(); itr != li.end(); itr++)
//     {
//         cout << itr->first << " " << itr->second << endl;
//     }
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     int _t; cin>>_t;while(_t--)
//     solve();
// }

// I dont know how to sort a list according to second element

// sort function in vectors sorts according to first element

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, string>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second;
        cin >> v[i].first;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cout << v[i].second << " " << v[i].first << endl;
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