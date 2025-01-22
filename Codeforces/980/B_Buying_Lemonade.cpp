// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     vector<int> arr(n);
//     for (auto &x : arr)
//         cin >> x;

//     sort(arr.begin(), arr.end());
//     int moves = 0, cnt = 0, cans = 0;

//     // cout << "cnt" << " " << "moves" << " " << "cans" << endl;
//     for (int i = 0; i < n; i++)
//     {

//         // if (cans >= k)
//         // {
//         //     cout << moves << endl;
//         //     return;
//         // }

//         if (arr[i] - cnt <= 0)
//         {
//             moves++;
//             // cout<<"No can left here arr[i], moves: "<< arr[i]<<" " << moves <<endl;
//             continue;
//         }

//         int temp = arr[i] - cnt;
//         int canBeCollect = cans + temp * (n - i);
//         // cans += temp * (n - i);
//         if (canBeCollect >= k)
//             moves += k - cans;
//         else
//             moves += (n - i) * temp + 1;
//         // cout << "Less can were there arr[i], moves: " << arr[i] << " " << moves << endl;
//         cans = canBeCollect;

//         cnt = arr[i];
//         // cout<< cnt <<" "<< moves<< " "<< cans<<endl;

//         if (cans >= k)
//         {
//             cout << moves << endl;
//             return;
//         }
//     }
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
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vpii vector<pii>
#define vvi vector<vi>
#define printArr(a, start, end)for(int i=start ; i<end ; ++i)cout << a[i] << " ";
#define readArr(a, start, end)for(int i=start ; i<end ; ++i)cin >> a[I];
#define read2D(mat, n, m)for(int i=0 ; i<n ; ++i)for(int j=0 ; j<m ; ++j)cin >> mat[i][j];
#define F first
#define S second
#define B begin()
#define E end()
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define len(x) (int)x.length()
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a)) 
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a)) 
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a)) 
#define FOREACH(a, b) for (auto&(a) : (b)) 
#define int long long

const int MOD = 1e9 + 7;  


void solve(){
    int n,k;
    cin>>n>>k;
    vi v(n);
    for(auto &x : v)
    {
        cin>>x;
    }
    sort(all(v));
    int taken=0;
    int ans=k;

    FOR(i,0,n){
        v[i]-=taken;

        k-=min(k,(n-i)*v[i]);
        if(k==0) break;
        else ans++;
        taken+=v[i];
    }
    cout<<ans<<endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}