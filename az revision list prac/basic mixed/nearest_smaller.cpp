/*
You are given an array of N integers. For each position, find the nearest position to its left having a smaller value. (1-based indexing)
For each test case, print N space-separated integers, 
for each position, the nearest position to its left having a smaller value.  If no position to its left has a smaller value, print 0.
*/

/*
This problem can be solved efficiently using a stack. The idea is to traverse the array from left to right, and maintain a stack of indices. 
For each index i, we keep popping indices from the stack until we find an index j such thata[j]<a[i]. 
The answer for index i is then j, or−1 if no such index exists.

Here is the step-by-step algorithm:

Initialize an empty stack.
Traverse the array from left to right.
For each index i:
While the stack is not empty and a[top of stack] >= a[i], pop the stack.
If the stack is empty, the answer for index i is − 1 .
Otherwise, the answer for index i is the index at the top of the stack.
Push index i onto the stack.
Return the list of answers.
Time Complexity per test case:O(N)
*/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<int> st;
    
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }

        if(st.empty()){
            cout<<'0'<<" ";
            st.push(i);
        }
        else{
            cout<<st.top()+1<<' ';
            st.push(i);
        }
    }

    cout << '\n';
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

// my first solution  was bit complex in if-else condiitons
//  #include <bits/stdc++.h>
//  using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     stack<int> st;
//     list<int> li;

//     for (int i = 0; i < n; i++)
//     {
//         if (st.empty() || arr[st.top()] < arr[i])
//         {

//             if (i == 0)
//             {
//                 li.push_back(0);
//             }
//             else if (!st.empty())
//             {
//                 li.push_back(st.top() + 1);
//             }
//             st.push(i);
//         }
//         else if (arr[st.top()] >= arr[i])
//         {
//             while (!st.empty() && arr[st.top()] >= arr[i])
//             {
//                 st.pop();
//             }

//             if (st.empty())
//             {
//                 st.push(i);
//                 li.push_back(0);
//             }
//             else
//             {
//                 li.push_back(st.top() + 1);
//                 st.push(i);
//             }
//         }
//     }
//     for (auto v : li)
//     {
//         cout << v << ' ';
//     }
//     cout << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int _t;
//     cin >> _t;
//     while (_t--)
//         solve();
// }
