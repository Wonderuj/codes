// // minimum element in a subarrray
// // Using sets
// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     multiset<int> mt;
//     for (int i = 0; i < n; i++)
//     {
//         mt.insert(arr[i]);
//         if (i - k >= 0)
//         {
//             mt.erase(mt.find(arr[i - k]));
//         }
//         if (i >= k - 1)
//         {
//             cout << *mt.begin() << '\n';
//         }
//     }
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }
//Time complexity O(N*Log n)
//-------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------

//METHOD 2 - Using Sliding Window / Monotone dequeue

#include<bits/stdc++.h>
using namespace std;
struct monotone_dq{
    deque<int>dq;
    void insert(int x){
        if(!dq.empty() && dq.back()>x){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void remove(int x){
        if(dq.front()==x){
            dq.pop_front();
        }
    }
    int getMin(){
        return dq.front();
    }
};

void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    monotone_dq mt;
    for(int i=0;i<n;i++){
        mt.insert(arr[i]);
        if(i-k>=0){
            mt.remove(arr[i-k]);
        }
        if(i>=(k-1)){
            cout<< mt.getMin()<<'\n';
        }
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}
