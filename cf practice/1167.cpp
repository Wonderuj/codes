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

vi edges[500100];
bool vis[500100];
void solve(){
    int n, m;
    cin >> n >> m;

    rep(i,0,m){
        int k;
        cin>>k;
        vi temp(k);
        
        rep(i,0,k){
            cin>>temp[i];
            --temp[i];
        }

        for(int j=0;j+1<k;j++){
            edges[temp[j]].pb(temp[j+1]);
            edges[temp[j+1]].pb(temp[j]);
        }
    }
    vi a(n);
    rep(i,0,n){
        if(!vis[i]){
            vi comp;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                if(vis[x]) continue;
                vis[x]=1;
                comp.pb(x);
                for (auto y : edges[x])
                {
                    if(!vis[y])
                        q.push(y);
                }
            }

            for(auto x:comp) a[x]=comp.size();
        }
    }

    for(auto x:a) cout<<x<<" ";


}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}