#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin >> n>>k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // ds for 2 pointers condition checking
    int cntzero = 0;
    // pointers
    int head = -1, tail = 0;
    int ans=0;
    while (tail < n)
    {       //while there is next element to take and we dont violate any condition then move the head forward

        while ((head + 1 < n) && ((arr[head + 1] == 1 && cntzero <= k) || (arr[head + 1] == 0 && cntzero < k))){
            head++;
            if(arr[head]==0){ cntzero++;}
        }
        //cout<<tail<<" "<<head<<endl;  this is way to debug 2 pointer code by checking outputs of head and tail positions
        //updating the answer accordingly
        ans= max(ans, head-tail+1);
        //move the tail ahead and remove last elements contribution
        if(head>=tail){
            if(arr[tail]==0){
                cntzero--;
            }
            tail++;
        }
        else          //if head is behind tail and moving head forward is not possible then we update the tail and start a new subsequence.
        {
            tail++;
            head = tail - 1;
        }
    }
    cout<<ans<<endl;

}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}