
// //LCS problem modified to 3 srings.

// #include<bits/stdc++.h>
// using namespace std;
// string s1,s2,s3;
// int n,m,k;
// int dp[202][202][202];

// int rec(int l1,int l2, int l3){
//     //basecase
//     if(l1==n||l2==m|| l3 ==k){           //one of string level reaches the end. so there is no matching from an empty element
//         return 0;
//     }

//     //cache check
//     if(dp[l1][l2][l3]!=-1){
//         return dp[l1][l2][l3];
//     }

//     //compute
//     int ans=0;
//     if(s1[l1]==s2[l2] && s2[l2]==s2[l3]){
//         ans =max(ans, 1+ rec(l1+1,l2+1,l3+1));
//     }
//     else{
//         ans = max({rec(l1, l2, l3 + 1), rec(l1 + 1, l2, l3), rec(l1, l2 + 1, l3)});  //discarding one of the characters from each one of them and chekcing which will give maximum
//     }
//     return dp[l1][l2][l3]=ans;
// }

// void solve(){
//     cin>>s1>>s2;
//     n=s1.length();
//     m= s2.length();
//     k=s3.length();
//     memset(dp,-1,sizeof(dp));
//     cout<<rec(0,0,0)<<endl;

// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }

//--------------------------------------------LCS for n number of strings---------------------------

// #include <bits/stdc++.h>
// using namespace std;
// int k;
// vector<string> s;
// map<vector<int>,int> dp;
// int rec(vector<int>l){
//     for(int i=0;i<k;i++){
//         if(l[i]==s[i].length()){
//             return 0;                           //base case
//         }
//     }
//     if(dp.find(l)!=dp.end()){
//         return dp[l];
//     }
//     int ans=0;
//     set<char>st;
//     for(int i=0;i<k;i++){
//         st.insert(s[i][l[i]]);    //insetring l[i]th character of ith index string in vector s
//         if(st.size()>1){
//             break;
//         }
//     }
//     if(st.size()==1){
//         vector<int>temp=l ;
//         for(int i=0;i<k;i++){
//             temp[i]++;                  //whatever the value was at l we are going at l++
//         }
//         ans = 1 + rec(temp);
//     }
    

//     for(int i=0;i<l.size();i++){
//         l[i]++;
//         ans=max(rec(l),ans);
//         l[i]--;
//     }

//     return dp[l];
// }
// void solve()
// {
//     cin >> k;
//     s.resize(k);
//     for (int i = 0; i < k; i++)
//     {
//         cin >> s[i];
//     }
//     vector<int> temp(k, 0); // a vector of k zeros
//     cout << rec(temp) << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }
#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3;
int n, m, k;
int dp[102][102][102];

int rec(int l1, int l2, int l3)
{
    // basecase
    if (l1 == n || l2 == m || l3 == k)
    { // one of string level reaches the end. so there is no matching from an empty element
        return 0;
    }

    // cache check
    if (dp[l1][l2][l3] != -1)
    {
        return dp[l1][l2][l3];
    }

    // compute
    int ans = 0;
    if (s1[l1] == s2[l2] && s2[l2] == s3[l3])
    {
        ans = (ans, 1 + rec(l1 + 1, l2 + 1, l3 + 1));
    }
    else
    {
        ans = max({rec(l1, l2, l3 + 1), rec(l1 + 1, l2, l3), rec(l1, l2 + 1, l3)}); // discarding one of the characters from each one of them and chekcing which will give maximum
    }
    return dp[l1][l2][l3] = ans;
}

void solve()
{
    cin >> s1 >> s2 >> s3;
    n = s1.length();
    m = s2.length();
    k = s3.length();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    while (_t--)
        solve();
}

