// // #include<bits/stdc++.h>
// // using namespace std;

// // void solve(){
// //     int n;
// //     cin>>n;

// //     string s="aeiou";

// //     int i=0;
// //     string ans;
// //     int counter=0;
// //     while(i!=n){
// //         ans.push_back(s[counter]);
// //         counter=(counter==4)?0:counter+1;
// //         i++;
// //     }
// //     cout<<ans<<endl;
// // }
// // signed main(){
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);cout.tie(0);

// //     int _t; cin>>_t;while(_t--)
// //     solve();
// // }

// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;
//     string s = "aeiou";
//     vector<int> a(5, 0);
//     int i = 0;
//     int counter = 0;
//     while (i != n)
//     {
//         a[counter]++;
//         counter = (counter == 4) ? 0 : counter + 1;
//         i++;
//     }
//     string ans;

//     for(int i=0;i<a[3];i++){
//         ans.push_back('o');
//     }

//     for (int i = 0; i < a[2]; i++)
//     {
//         ans.push_back('i');
//     }
//     for (int i = 0; i < a[0]; i++)
//     {
//         ans.push_back('a');
//     }
//     for (int i = 0; i < a[1]; i++)
//     {
//         ans.push_back('e');
//     }
//     for (int i = 0; i < a[4]; i++)
//     {
//         ans.push_back('u');
//     }

//     cout<<ans<<endl;
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

void solve(){
    int n;
    cin>>n;
    
    string s="aeiou";
    string ans;

    int counter=0;
    for(int i=0;i<n;i++){
        ans.push_back(s[counter]);
        counter=(counter==4)?0:counter+1;
    }
    sort(ans.begin(),ans.end());
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}