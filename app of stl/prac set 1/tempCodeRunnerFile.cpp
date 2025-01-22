#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

void solve()
{
 int n;
 cin>>n;
 long long prod=1;
 int a[n];
 for(int i=0;i<n;i++){
   cin>>a[i];
 }
 for(int i=0;i<n;i++){
  prod=(prod*a[i])%mod;
 }
 cout<<prod<<endl;
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);


  int _t; cin>>_t; while(_t--)
  solve();
}