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
#define readArr(a, start, end)for(int i=start ; i<end ; ++i)cin >> a[i];
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
#define int long long

const int MOD = 1e9 + 7;  


void solve(){
    int n; cin>>n;
    vi v(n);
    repauto(x,v) cin>>x;

    rep(i,0,n-1){
        int mini=min(v[i],v[i+1]);
        v[i]-=mini;
        v[i+1]-=mini;
    }

    rep(i,0,n-1){
        if(v[i]==0) continue;
        if(v[i]<v[i+1]){
            int mini = min(v[i], v[i + 1]);
            v[i] -= mini;
            v[i + 1] -= mini;
        }
        else if(v[i]>v[i+1]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}