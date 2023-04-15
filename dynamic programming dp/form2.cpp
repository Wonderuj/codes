//#maximum sum subarray

#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100100];
int dp[100100];
bool done[100100];
int rec(int level){
    //pruning and base case
    if(level<0){
        return 0;
    }

    //cache check
    if(done[level]){
        return dp[level];
    }

    //compute
    int ans= max(rec(level-1)+arr[level], arr[level]);       //always use recurrence on right side as we dont know wheather some dp is calc or not. rec will take care of that itself

    //save and return
    done[level]=1;  //flag on in that check array

    return dp[level]= ans;


}

void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>arr[i];
    }
    int ans=rec(0);                         //its best to choose one of the values and then use it insted of randomly assigning 0 or int min.
    //if ans=0 then it might fail the test case of -1 -1 -1 -1 array where best ans is -1 but we will be returned 0 insted.
    for(int i=1;i<n;i++){                         //we choose rec(0) as initial point so start looking from i=1
        ans=max(ans,rec(i));
    }
    cout<<rec(n-1)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}