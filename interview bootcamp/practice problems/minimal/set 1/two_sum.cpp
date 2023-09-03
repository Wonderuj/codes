// O(N log N)

// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {

//     int n, s;
//     cin >> n >> s;
//     vector<int> v(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i];
//     }
//     if (n == 1)
//     {
//         cout << "N\n";
//         return;
//     }
//     sort(v.begin(), v.end());
//     bool ispresent = false;
//     for (auto it = v.begin(); it != v.end(); ++it)
//     {
//         auto itr = lower_bound(v.begin(), v.end(), s - *it);
//         if (itr != v.end() && itr != it)
//         {
//             if (*it + *itr == s)
//             {
//                 ispresent = true;
//                 break;
//             }
//         }
//     }
//     cout << (ispresent ? 'Y' : 'N') << '\n';
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

//--------------------------------------------------


//O(N log N) using map

// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n, s;
//     cin >> n >> s;
//     vector<int> v(n);
//     unordered_map<int, int> mp;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         v[i] = x;
//     }

//     if (n == 1)
//     {
//         cout << "N\n";
//         return;
//     }
//     bool ispresent = false;
    
//     for (int i = 0; i < n; i++)
//     {
//         if (mp[s - v[i]]>0)
//         {
//             ispresent = true;
//             break;
//         }
//         mp[v[i]]++;
//     }

//     cout << (ispresent ? 'Y' : 'N') << '\n';
//     mp.clear();
//     v.clear();
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

//-----------------------------------------------

//using 2 pointers O(N log N)

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,s;
    cin>>n>>s;
    vector<int>v(n);
    for(auto &x :v){
        cin>>x;
    }

    sort(v.begin(),v.end());
    int left=0, right=n-1;
    bool ispresent=false;
    while(left<right){
        if(v[left]+v[right]==s){
            ispresent=true;
            break;
        }
        else if (v[left] + v[right]<s){
            left++;
        }
        else{
            right--;
        }
    }
    cout<<(ispresent?'Y':'N')<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}