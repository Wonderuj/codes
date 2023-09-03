/* Question
You are given N blocks. You have to build towers by placing blocks on top of each other,
with the condition that the upper block must be smaller than the lower block. You have to process the blocks in the given order.
Find the minimum possible number of towers you can create.*/

//-------------------------------------------------------------------------
// Solution
/*
The key idea here is that we want to maintain a set of blocks that can be used as the top of a tower. Initially, the set is empty,so any block can be used to start a new tower.
For each subsequent block, we want to find the smallest block in the set that is just greater than the current block.
If such a block exists, we can add the current block to the top of that tower by replacing the old block in the set with the new block.
Otherwise, we must start a new tower with the current block and insert this number in the set. \
By maintaining this set, we can ensure that we always use the smallest possible block as the top of each tower, which will minimize the total number of towers required.

For each test case:
-Read the number of blocks.
-Create an empty multiset to keep track of the blocks used to build towers.
-For each block in the given order:
    -Find the iterator to the smallest element in the multiset that is greater than the current block.
    -If such an iterator is not found (i.e., the current block is greater than all blocks in the multiset), insert the block into the multiset.
    -If such an iterator is found, erase that element from the multiset and insert the current block.

The size of the multiset after all blocks have been processed gives the minimum number of towers that can be built.

Time Complexity per test case:
O(NlogN)
*/

// Method 1 using Multiset
//  #include<bits/stdc++.h>
//  using namespace std;

// void solve(){
//     int n;
//     cin>>n;

//     multiset<int> st;

//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;

//         auto it=st.upper_bound(x);

//         if(it==st.end()){
//             st.insert(x);
//         }
//         else{
//             st.erase(it);
//             st.insert(x);
//         }
//     }
//     cout<<st.size()<<endl;
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     int _t; cin>>_t;while(_t--)
//     solve();
// }

// method 2 using vector

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v; // maintaining the vector with towers top
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        auto it = upper_bound(v.begin(), v.end(), x);
        if (it != v.end())
        {
            *it = x;
        }
        else
        {
            v.push_back(x);
        }
    }
    cout << v.size() << '\n';
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
