//first the brute force soltution that dosent have dp
// #include<bits/stdc++.h>
// using namespace std;

// int n,m;x
// int arr[1001][1001];

// pair<bool,int> rec(int i, int j){
//     //pruning statement/ handeling the edge case

//     if(i>=n||j>=m){   //checking if loop goes out of range
//         return {0,0};        //not possible hence we return 0 in bool, that shows dont go with this route.
//     }
//     //base case
//     if(i==n-1 && j==m-1){       //when it reaches the finish
//         return {1, arr[n-1][m-1]};  //returning 1 and the score of that cell
//     }
//     //compute recursion with return 
//     pair<bool,int> cur= max(rec(i,j+1), rec(i+1,j));                //recursion and finding out the max path.
//     //if (0,5) and (1,2) is returned then max will be (1,2).. we see that 0 path will not be taken due to smart optimisations like this
//     cur.second+=arr[i][j];                                          //we are adding the current cell value to the sum obtained from path ahead.
//     return cur;
// }

// void solve(){
//     cin>>n>>m;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//         }
//     }
    
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }

// now we add dp to the solution


#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[1001][1001];
//1) the type of dp table will be same as type of return of recursion

pair<bool, int> dp[1001][1001];
bool cached[1001][1001];          //making a cached array to see if dp have saved valued or not

pair<bool, int> rec(int i, int j)
{
    //pruning statement/ handeling the edge case

    if(i>=n||j>=m && arr[i][j]==0){   //checking if loop goes out of range or its blocked (score =0)
        return {0,0};        //not possible hence we return 0 in bool, that shows dont go with this route.
    }
    //base case
    if(i==n-1 && j==m-1){       //when it reaches the finish
        return {1, arr[n-1][m-1]};  //returning 1 and the score of that cell
    }


 //2) check cache and return
    if(cached[i][j]){
        return dp[i][j];
    }
    //compute with recursion
    pair<bool,int> cur= max(rec(i,j+1), rec(i+1,j));                //recursion and finding out the max path.
    //if (0,5) and (1,2) is returned then max will be (1,2).. we see that 0 path will not be taken due to smart optimisations like this
    cur.second+=arr[i][j];                          //we are adding the current cell value to the sum obtained from path ahead.

//3) we computre the value of cur above and save it in dp
    //save and return
    dp[i][j]=cur;
    cached[i][j]=true;
    return cur;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            cached[i][j]=0;        //assigning cached array to all 0
        }
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}