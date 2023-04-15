// #include<bits/stdc++.h>
// using namespace std;
//  //comparator function for sort
//  bool comp(pair<int, int> &a ,pair<int, int> &b){
//     //condition true for a before b
//     return a.first + a.second > b.first + b.second;       //we never use equals in the comparator function
//  } 

// void solve(){
//     int n; cin>>n;
//     vector<pair<int, int>> cards(n);
//     for(int i=0;i<n;i++){
//         cin>>cards[i].first>>cards[i].second;
//     }
//     sort(cards.begin(), cards.end(),comp);
    
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }
//---------------------------------------------------------------------------------------

// Number of subarrays of with sum X

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n,x;
//     cin>>n>>x;
//     int p[n];
//     for(int i=0;i<n;i++){
//         cin>>p[i];
//         if(i){
//             p[i]+=p[i-1];        //building the prefix sum right there while taking the input.
//         }
//     }
//     map<int,int> mp;             // we made a frequency map
//     int sum=0;
//     mp[0]++;                     // inserting 0 at starting of prefix sum
//     for(int i=0;i<n;i++){
//         sum+=mp[p[i]-x];         //Finding the number of Left side element (P[R]-x) in frequency map and adding it to sum
//         mp[p[i]]++;              //Adding this current element to the map for next iteration
//     }    
//     cout<<sum;
//     return 0;
// }
// 5 0
// 1 - 1 1 - 1 0
// prefix sum array- 0 1 0 1 0 0 (inserted 0 by ourselves)
//-------------------------------------------------

//  To print the index of right and left side of subarray of size x

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (i)
        {
            p[i] += p[i - 1]; // building the prefix sum right there while taking the input.
        }
    }
    int sum = 0;
    map<int, vector<int>> mp; // we made a frequency map
    mp[0].push_back(-1); // inserting 0 at starting of prefix sum
    for (int i = 0; i < n; i++)
    {
        sum += mp[p[i] - x].size();
        for(auto v: mp[p[i]-x])
        {
            cout<<v+1<<","<<i<<endl;
        }
        mp[p[i]].push_back(i);          // Adding this current element to the map for next iteration
    }
    cout <<sum <<endl;
}