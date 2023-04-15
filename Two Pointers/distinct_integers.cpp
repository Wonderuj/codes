// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     set<int> s;
//     map<int, int> mp;
//     int v[100100];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i];
//         // s.insert(v[i]);
//     }

//     // int x = s.size();
//     int tail = 0, head = -1;
//     int ans = 0;
//     while (tail < n)
//     {
//         while (head + 1 < n && mp.size()<k)
//         {
//             if (mp.find(v[head+1]) != mp.end() )
//                 ans++;
//                 head++;
//             head++  ;
//             mp[v[head]]++;
//         }
//         if (mp.size() == k)
//         {
//             ans++;
//         }

//         cout << head << " head-tail " << tail << endl;
//         cout << ans << " ans,mp.size() " << mp.size() << endl;

//         if(head>=tail){
//             mp[v[tail]]--;
//             if(mp[v[tail]]==0){
//                 mp.erase(v[tail]);
//             }
//             tail++;
//         }
//         else{
//             tail++;
//             head=tail-1;
//         }
//     }
//     cout<<ans<<endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//      int _t; cin>>_t;while(_t--)
//     solve();
// }

// this was very wrong approach because 2 pointers cant be implemented directily here

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n, k;
vector<int> freq(1001000,0);
vector<int> arr;

int atmostk(int k)
{
    int cnt=0, ans=0;
    int head = -1, tail = 0;
    while (tail < n)
    {
        while (head + 1 < n && (freq[arr[head + 1]] != 0 || cnt < k)){
            head++;
            freq[arr[head]]++;
            if(freq[arr[head]]==1){
                cnt++;
            }
        }
        ans+=head-tail+1;
        //cout<<head<<" "<<tail<<endl;
        if(head>=tail){
            freq[arr[tail]]--;
            if (freq[arr[tail]]==0){
                cnt--;
            }
            tail++;
        }
        else{
            tail++;
            head=tail-1;
        }
    }
    for(int i=0;i<n;i++){
        freq[arr[i]]=0;
    }
    return ans;
}
void solve()
{
    cin >> n >> k;
   
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<atmostk(k)-atmostk(k-1)<<endl;
    
}
signed main()
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}