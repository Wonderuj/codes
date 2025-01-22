// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     // string s[5];
//     // for(int i=0;i<5;i++){
//     //     cin>>s[i];
//     // }
//     char ch;
//     int x,y;
//     for(int i=0;i<5;i++){
//         for(int j=0;j<5;j++){
//             cin>>ch;
//             if(ch=='1'){
//                 x=i+1;
//                 y=j+1;
//                 break;
//             }
//         }
//     }
//     cout<<abs(x-3)+abs(y-3)<<"\n";

// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }


//q) UNIT ARRAY
// -1 -1  -1- 1 1> -1 =  -> 


#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);


    int c1 = 0, c0 = 0;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0)
            c1++;
        else
            c0++;
    }
    int ans = 0;
    while (c0 % 2 == 1 || c0 > c1)
        c0--, c1++, ans++;
    cout << ans << "\n";
    
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