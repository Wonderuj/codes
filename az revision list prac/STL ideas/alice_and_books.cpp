/*Question
Alice read N books. The i-th book has Ai pages. After every book Alice reads, 
you have to tell the largest integer B such that Alice has read B books that have at least B pages.
*/

#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int freq[100010]={};
    
    int b = 0;          //number of books having atleast b pages
    int cnt = 0;        // number of books having > b pages
    for (int i = 0; i < n; i++)
    {
        int x;          
        cin >> x;
        freq[x]++;          //storing the number of book having x number of pages
        if (x > b)
        {                   //if current book have pages >b, it will participate in count
            cnt++;
        }
        if (cnt > b)
        {               //if count>b then we will increase b by 1. (we found b+1 with atleast b+1 pages)
            b++;            
            cnt -= freq[b];     //removing contribution of current b pages books from the count as we have to check for increased b next time.
        }                       //its like a running count updation.
        cout << b << " ";
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

/*Solution
Initially, the number of books read is 0. After each book is read, we need to update the answer. We can use priority queue/multiset to store the number of books. For each book read, you have to do the following:

If the number of pages is greater than the current answer, add it in the priority queue/multiset.
Remove the books which have pages not greater than the current answer.
If the size of priority queue/multiset is greater than the current answer, increment the answer by 1.
Time Complexity per test case: O(N*logN)

A solution with linear time complexity is possible if we store the number of pages in each book in a frequency array. Initially, the number of books read is 0. For each book read, you have to do the following:

Increase the frequency of the number of pages.
If the number of pages is greater than the current answer, increase the count of books that have a greater number of pages than the current answer.
If the count of books that have a greater number of pages than the current answer is greater than the current answer, increment the current answer by 1. This is because now we have more than cur books with at least cur number of pages. (here cur denotes the current answer). Reduce the frequency of the current answer from the count of books that have a greater number of pages than the current answer.
Time Complexity per test case: O(N)
*/


//.. other solution using set


// #include <bits/stdc++.h>
//     using namespace std;

// #define IOS                  \
//     ios::sync_with_stdio(0); \
//     cin.tie(0);              \
//     cout.tie(0);

// int main()
// {
//     IOS int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         multiset<int> s;
//         int b = 1;
//         for (int i = 0; i < n; ++i)
//         {
//             int x;
//             cin >> x;
//             if (x > b)
//             {
//                 s.insert(x);
//             }
//             while (!s.empty() && *s.begin() <= b)
//             {
//                 s.erase(s.begin());
//             }
//             if (s.size() > b)
//             {
//                 b++;
//             }
//             cout << b << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }
