// ugly number - The below code is to print first n ugly number with complexity of O(N logn) (N times loop and 3 insertion and erase with log N)
#include <bits/stdc++.h>
using namespace std;
/*bool check_ugly(int n){
    while(n%2==0) n/=2;
    while(n%3==0) n/=3;
    while(n%5==0) n/=5;

    return n==1;
}
This was for the brute force soltuion
*/

// now a greedy solution
//  void solve(){
//   int n; cin>>n;
//   set<int>s;
//   s.insert(1);
//   for(int i=0;i<n;i++){
//      int cur= *s.begin();

//     s.erase(s.find(cur));
//     s.insert(2*cur);
//     s.insert(3*cur);
//     s.insert(5 * cur);
//     cout<<cur<<" ";
//  }
//  cout<<endl;
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }

//--------------------- Optimised greedy solution
// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> ugly(n+1);
//     ugly[1] = 1;
//     int ptr2 = 1, ptr3 = 1, ptr5 = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         ugly[i] = min(2 * ptr2, min(3 * ptr3, 5 * ptr5));

//         if (ugly[i] == 2 * ugly[ptr2])
//             ptr2++;
//         if (ugly[i] == 3 * ugly[ptr3])
//             ptr3++;
//         if (ugly[i] == 5 * ugly[ptr5])
//             ptr5++;
//     }
//     for(int i=1;i<=n;i++){
//         cout<<ugly[i]<<" ";
//     }
//     cout<<endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }

////-------------------------------------------------------------------------------------------///////////

#include<bits/stdc++.h>
using namespace std;

void solve(){
 string s;
 cin>>s;
 int n=(int)s.length();
 int k;
 cin>>k;
 stack<int>st;
 for(int i=0;i<n;i++){
    while(!st.empty() && s[st.top()]<s[i] && n-1-i >=k-(int)st.size()){
        st.pop();
    }
    if((int)st.size()<k){
        st.push(i);
    }
 }
 string ans;
 while(!st.empty()){
    ans+=s[st.top()];
    st.pop();
 }
 reverse(ans.begin(),ans.end());
 cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}