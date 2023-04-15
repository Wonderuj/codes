//##stone paper sissor game

// #include<bits/stdc++.h>
// using namespace std;
// int n,k;
// string comp;
// int arr[100100];
// map<char,int>mp;
// int dp[100100][3][101];
// int result(int mymove,int compmove){
//     //P=0, H=1, S=2 ,, (0,1) (1,2), (2,0) are the winning cases for me
//     //here we could have made differnt cases of if and else and return who will win but insead by seeing pattern we can write this:
//     return compmove==(mymove+1)%3; 
// }
// int rec(int level,int last, int ch_left){
//     //pruning
//     if(ch_left<0){
//         return -1e9;      //one of the 3 cases will be posigive value(case of not change of character) and that will be taken as vakid case in max fun.
//     }
//     if(level==n){ 
//         return 0;   //no character left
//     }

//     //cache check
//     if(dp[level][last][ch_left]!=-1)
//         return dp[level][last][ch_left];

//     //transition
//     int ans=0;

//     for(int x=0;x<3;x++){
//         ans=max(ans, result(x,arr[level])+rec(level+1,x,ch_left-((x==last)?0:1)));
//     }
//     return dp[level][last][ch_left]=ans;
// }

// void solve(){
//     cin>>n>>k;
//     cin>>comp;
//     for(int i=0;i<n;i++){
//         arr[i]=mp[comp[i]];
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<3;j++){
//             for(int x=0;x<=k;x++){
//                 dp[i][j][k]=-1;
//             }
//         }
//     }
//     cout << max(rec(0, 0, k), rec(0, 1, k), rec(0, 2, k))<<endl;  //we can have any input from paper sirror or stone on the start, so printing the one that gives maximum answer
// }
// signed main(){
//     mp['P']=0;
//     mp['H']=1;
//     mp['S']=2;
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }


//if we wnat to Print the soltuions too

// #include <bits/stdc++.h>
// using namespace std;

// #define MP make_pair

// int n, k;
// string comp;
// int arr[100100];
// map<char, int> mp;
// map<int, char> rmp;
// // P=0, H=1, S=2
// // (0,1), (1,2), (2,0)
// int result(int mymove, int compmove)
// {
//     return compmove == (mymove + 1) % 3;
// }

// int dp[100100][3][101];
// vector<int> back[100100][3][101];

// int rec(int level, int last, int ch_left)
// {
//     if (ch_left < 0)
//         return -1e9;
//     if (level == n)
//     {
//         return 0;
//     }
//     if (dp[level][last][ch_left] != -1)
//         return dp[level][last][ch_left];

//     int ans = 0;
//     back[level][last][ch_left] = {};

//     for (int x = 0; x < 3; x++)
//     {
//         int temp = result(x, arr[level]) + rec(level + 1, x, ch_left - ((x == last) ? 0 : 1));

//         if (temp > ans)
//         {
//             back[level][last][ch_left] = {x};
//         }
//         else if (temp == ans)
//         {
//             back[level][last][ch_left].push_back(x);
//         }
//     }

//     return dp[level][last][ch_left] = ans;
// }

// vector<string> all_sol;
// string cur_sol;

// void generate(int level, int last, int ch_left)
// {
//     if (level == n)
//     {
//         all_sol.push_back(cur_sol);
//         return;
//     }
//     for (auto x : back[level][last][ch_left])
//     {
//         cur_sol += rmp[x];
//         generate(level + 1, x, ch_left - ((x == last) ? 0 : 1));
//         cur_sol.pop_back();
//     }
// }

// void solve()
// {
//     cin >> n >> k;
//     cin >> comp;
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = mp[comp[i]];
//     }
//     for (int i = 0; i <= n; i++)
//         for (int j = 0; j < 3; j++)
//             for (int x = 0; x <= k; x++)
//             {
//                 dp[i][j][x] = -1;
//             }

//     // pair<int,int> ans  = max({MP(rec(0,0,k),0),MP(rec(0,1,k),1),MP(rec(0,2,k),2)});
//     // cout<<ans.first<<endl;
//     // generate(0,ans.second,k);
//     // cout<<final_ans<<endl;

//     int ans = 0;
//     int best = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         int temp = rec(0, i, k);
//         if (temp > ans)
//         {
//             ans = temp;
//             best = i;
//         }
//     }
//     cout << ans << endl;
//     generate(0, best, k);
//     cout << final_ans << endl;
// }

// int main()
// {
//     mp['P'] = 0;
//     mp['H'] = 1;
//     mp['S'] = 2;
//     rmp[0] = 'P';
//     rmp[1] = 'H';
//     rmp[2] = 'S';
//     solve();
// }



//------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
int n,k;
string comp;
int arr[100100];
map<char,int>mp;
map<char, int> rmp;
int dp[100100][3][101];
int back[100100][3][101];
int result(int mymove,int compmove){
    //P=0, H=1, S=2 ,, (0,1) (1,2), (2,0) are the winning cases for me
    //here we could have made differnt cases of if and else and return who will win but insead by seeing pattern we can write this:
    return compmove==(mymove+1)%3;
}
int rec(int level,int last, int ch_left){
    //pruning
    if(ch_left<0){
        return -1e9;      //one of the 3 cases will be posigive value(case of not change of character) and that will be taken as vakid case in max fun.
    }
    if(level==n){
        return 0;   //no character left
    }

    //cache check
    if(dp[level][last][ch_left]!=-1)
        return dp[level][last][ch_left];

    //transition
    int ans=0;
    back[level][last][ch_left] == -1;
    for(int x=0;x<3;x++){
        ans=max(ans, result(x,arr[level])+rec(level+1,x,ch_left-((x==last)?0:1)));
        if (ans == result(x, arr[level]) + rec(level + 1, x, ch_left - ((x == last) ? 0 : 1))){
            back[level][last][ch_left]==x;     //this move was done so we save this is in back array and use in print function
        }
    }
    return dp[level][last][ch_left]=ans;
}
string final_str;
void generate(int level, int last, int ch_left){
    if(level==n) return;
    int x = back[level][last][ch_left];
    final_str+=rmp[x];
    generate(level + 1, x, ch_left - ((x == last) ? 0 : 1));
}

void solve(){
    cin>>n>>k;
    cin>>comp;
    for(int i=0;i<n;i++){
        arr[i]=mp[comp[i]];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            for(int x=0;x<=k;x++){
                dp[i][j][k]=-1;
            }
        }
    }
    //cout << max(rec(0, 0, k), rec(0, 1, k), rec(0, 2, k))<<endl;  //we can have any input from paper sirror or stone on the start, so printing the one that gives maximum answer
    pair<int,int> ans  = max({MP(rec(0,0,k),0),MP(rec(0,1,k),1),MP(rec(0,2,k),2)});  //by this way get store which char was used as first move to get max ans
        cout<<ans.first<<endl;  
        generate(0,ans.second,k);
        cout<<final_str<<endl;
}
signed main(){
    mp['P']=0;
    mp['H']=1;
    mp['S']=2;
    rmp[0] = 'P';
    rmp[1] = 'H';
    rmp[2] = 'S';
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}
