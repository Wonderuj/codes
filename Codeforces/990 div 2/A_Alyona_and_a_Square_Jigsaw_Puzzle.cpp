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
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a)) 
#define repn(a, b, c) for (int(a) = (b); (a) <= (c); ++(a)) 
#define repd(a, b, c) for (int(a) = (b); (a) >= (c); --(a)) 
#define repauto(a, b) for (auto&(a) : (b)) 
// #define int long long

const int MOD = 1e9 + 7;




void solve(){
    int n;
    cin>>n;
    vi v(n);
    repauto(x,v) cin>>x;

    set<int> st;
    int x = 1;
    for (int i = 1; i < 100; i++)
    {
        x +=( 8 * i);
        st.insert(x);
    }

    // for(auto x:st) cout<<x<<" ";
    // cout<<endl;
    int sum=0, happy=1;

    rep(i,0,n){
        sum+=v[i];
        if(st.find(sum)!=st.end()){
            happy++;
        }
    }
    cout<<happy<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}