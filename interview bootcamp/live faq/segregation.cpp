/*given an integer array nums with n integers in it, you have to move all zeros present to the end,
maintianing the relative order of the rest of the elements. Solve in O(1) space. 
example- [0 2 0 0 1 3] -> Output-> [2 1 3 0 0 0]
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ptr=0;  //pointer helps to make a segretation b/w non-zero elements and zeros. it points just ahead of non-zero partition being formed on left
    int cur=0;
    while(cur<n){
        if(v[cur]!=0){
            swap(v[cur],v[ptr]);
            ptr++;
        }
        cur++;
    }
    for(auto x:v){
        cout<<x<<" ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}