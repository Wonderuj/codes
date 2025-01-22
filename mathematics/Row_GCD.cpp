#include<bits/stdc++.h>
using namespace std;
// #define ll long long int
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define MOD (ull)(double)(1e9 + 7)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define pull pair<ull, ull>
#define m_p make_pair
#define debug(x) cout << #x << " " << x << endl
#define printArr(a, start, end)for(int i=start ; i<end ; ++i)cout << a[i] << " ";
#define readArr(a, start, end)for(int i=start ; i<end ; ++i)cin >> a[i];
#define read2D(mat, n, m)for(int i=0 ; i<n ; ++i)for(int j=0 ; j<m ; ++j)cin >> mat[i][j];
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define int long long
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

void solve(){
    int n,m;
    cin>>n>>m;
    vi arr(n),brr(m);
    readArr(arr,0,n);
    readArr(brr,0,m);
    sort(all(arr));

    int precom_val=0;
    FOR(i,1,n){
        precom_val=gcd(arr[i]-arr[0],precom_val);
    }

    FOR(j,0,m){
        cout<<gcd(precom_val,arr[0]+brr[j])<<" ";
    }


}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}