//Q) Goals of victory

// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n;
//     cin>>n;
//     int sum=0;
//     for(int i=0;i<n-1;i++){
//         int x; cin>>x;
//         sum+=x;
//     }
//     cout<<-sum<<'\n';
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     int _t; cin>>_t;while(_t--)
//     solve();
// }

//---------------------------------------------------------------------------------------------------
/*Q) Make array beautiful -https://codeforces.com/contest/1783/problem/A
Good tutorial explaination
*/
#include<bits/stdc++.h>
using namespace std;
#define printArr(a, start, end)for(int i=start ; i<end ; ++i)cout << a[i] << " ";
#define readArr(a, start, end)for(int i=start ; i<end ; ++i)cin >> a[i];
#define debug(x) cout << #x << " " << x << endl

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    readArr(v,0,n);
    
    if(v[0]==v[n-1]) {
        cout<<"NO\n";
        return;
    }
    
    cout<<"YES\n";
    cout<<v[n-1]<<" ";
    printArr(v,0,n-1);
    cout<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}