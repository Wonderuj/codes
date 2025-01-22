#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    vector<int>v(3);
   
    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }
    int mini = *min_element(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<3;i++){
        if(v[i]==mini){
            continue;
        }
        else ans+=v[i]/mini;
    }
    if(ans-2<=3) cout<<"YES"<<endl;
    else cout<<"NO\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}