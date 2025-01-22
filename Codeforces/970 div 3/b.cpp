#include <bits/stdc++.h>
using namespace std;
set<int> squares;

void precom()
{
    int N = 1e6;
    for (int i = 1; i < N; i++)
    {
        squares.insert(i * i);
    }
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (squares.find(n) == squares.end())
    {
        cout << "NO\n";
        return;
    }
    int zeros=0;
    for(auto &x:s){
        if(x-'0'==0){
            zeros++;
        }
    }
    if(squares.find(zeros)==squares.end()){
        cout<<"NO"<<endl;
        return;
    }
    if(sqrt(zeros)==sqrt(n)-2){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    precom();
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}