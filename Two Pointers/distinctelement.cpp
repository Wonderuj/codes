// number of subarrays with number of distinct elements <=k

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int distinct = 0;
    map<int, int> freq;
    int head = -1, tail = 0;
    int ans=0;
    while(tail<n){
        while((head+1<n) && ((freq[arr[head+1]]==0 && distinct<k)|| (freq[arr[head+1]]>0 && distinct<=k))){
            head++;
            if(freq[arr[head]]==0){
                distinct++;
            }
            freq[arr[head]]++;
        }
        // cout<<tail<<" "<<head<<endl;
        // cout<<distinct<<endl;
        ans+= head-tail+1;

        if(head>=tail){
            freq[arr[tail]]--;
            if(freq[arr[tail]]==0){
                distinct--;
            }
            tail++;
        }
        else{
            tail++;
            head=tail-1;    
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}