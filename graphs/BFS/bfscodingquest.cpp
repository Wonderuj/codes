#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define rep0(i, n, m) for (int i = n; i < m; i++)
#define rep1(i, n, m) for (int i = n; i <= m; i++)
#define F first
#define S second
#define pb push_back
using ii = pair<int, int>;
#define vii vector<ii>

int n,m;
vector<string>arr;

//U, R,D,L
int dx[]={-1,0,+1,0};   //this is telling about the change that will happen in row for ith index(Up is 0, right is 1 etc), so like for up we will decrease the row by 1 so -1 is at 0th position
int dy[]={0,+1,0,-1} ;       // this is for column


bool check(int x, int y){
    if(x<n&&x>0&& y<m&&y>0&&arr[x][y]!='W'){
        return 1;
    }
    else return 0;
}
int bfs(vii pos[]){
    rep0(dir,0,4){
        for(auto v: pos[dir]){

        }
    }
}
void solve(){
    cin>>n>>m;
    arr.resize(n);
    ii st, en;
    vector<ii> pos[4];     //U, R, D, L
    rep0(i,0,n){
        cin>>arr[i];
        rep0(j,0,m){
            if(arr[i][j]=='S'){
                st={i,j};
            }
            else if(arr[i][j]=='N'){
                en={i,j};
            }
            else if(arr[i][j]=='U'){
                pos[0].pb({i,j});
            }
            else if (arr[i][j] == 'R')
            {
                pos[1].pb({i, j});
            }
            else if (arr[i][j] == 'D')
            {
                pos[2].pb({i, j});
            }
            else if (arr[i][j] == 'L')
            {
                pos[3].pb({i, j});
            }                                       //saved all the positions of police in a array of vectors.
        }
    }

    bfs(pos);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}