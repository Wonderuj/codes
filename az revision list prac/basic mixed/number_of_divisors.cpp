// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// int num_div(int x)
// {
//     vector<int> v;
//     for (int i = 1; i * i <= x; i++)
//     {
//         if (x % i == 0)
//         {
//             v.push_back(i);
//             if (i * i != x)
//             {
//                 v.push_back(x / i);
//             }
//         }
//     }
//     return v.size();
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     int ans = num_div(n);
//     cout << ans << '\n';
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

#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v;
int num_div(int x){
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            v.push_back(i);
            if(i*i!=x){
                v.push_back(x/i);
            }
        }
    }
    return v.size();
}

void solve(){
    int n;
    cin>>n;
    v.clear();
    int ans=num_div(n);
    cout<<ans<<'\n';

    //to print the divisors
    sort(v.begin(),v.end());
    for(int i=0;i<ans;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}