// #include<bits/stdc++.h>
// using namespace std;
// int n;
// map<int,int>mp;
// vector<vector<int>>all_sol;
// vector<int> cur_sol;
// void rec(int level){
//     //base case
//     if(level==n){
//         all_sol.push_back(cur_sol);
//         return;
//     }

//     //recursion
//     for(auto v:mp){
//         if(v.second!=0){   //if frequency is not zero then only we can put it in cur_sol
//              mp[v.first]--;
//              cur_sol.push_back(v.first);
//              rec(level+1);
//              cur_sol.pop_back();
//              mp[v.first]++;
//         }
//     }
// }

// void solve(){
// cin>>n;
// int arr[n];
// for(int i=0;i<n;i++){
//     cin>>arr[i];
//     mp[arr[i]++];
// }
// rec(0);
// for(auto j:all_sol){
//     for(auto v:cur_sol){
//         cout<<v<<" ";
//     }
//     cout<<endl;
// }
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }

#include <bits/stdc++.h>
using namespace std;
int n;
#define int long long
map<int, int> mp;
vector<vector<int>> all_sol;
vector<int> curr_sol;

void rec(int level)
{ // level is numbers in array
    // base case
    if (level == n)
    {
        all_sol.push_back(curr_sol);
        // for(auto v:curr_sol){
        //     cout<<v<<" ";              //to print the numbers method 1
        // } cout<<endl;
        return;
    }

    // recursion

    // choices
    for (auto v : mp)
    {
        if (v.second != 0)
        {
            mp[v.first]--;
            curr_sol.push_back(v.first);
            rec(level + 1);
            curr_sol.pop_back();
            mp[v.first]++;
        }
    }
}
void solve()
{
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mp[x]++;
    }
    rec(0);

    // for(int j=0; j<int(all_sol.size());j++){
    //     for(int k=0; k<int(all_sol[j].size());k++){          //to print the numbers method 2
    //         cout<<all_sol[j][k]<<" ";
    //     } cout<<'\n';
    // }
    for (auto j : all_sol)
    {
        for (auto k : j)
        {
            cout << k << " "; // to print the numbers method 3
        }
        cout << '\n';
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