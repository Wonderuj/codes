#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int height[n + 1], prev[n + 1], next[n + 1]; // given array, prevoius and next array to store the range in which current element is minimum
    for (int i = 1; i <= n; i++)
    { // using 1-indexed
        cin >> height[i];
    }

    stack<int> st;
    height[0] = -1e9;
    height[n + 1] = -1e9;

    // previous min
    st.push(0);
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && height[st.top()] >= height[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            st.push(i);
            prev[i] = i;
        }

        else
        {
            prev[i] = st.top();
            st.push(i);
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<prev[i]<<" ";  //to check and debug
    // }

    while (!st.empty())
    {
        st.pop();
    }

    // Next array

    st.push(n + 1);
    for (int i = n; i > 0; i--)
    {
        while (!st.empty() && height[st.top()] >= height[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            st.push(i);
            next[i] = i;
        }
        else
        {
            next[i] = st.top();
            st.push(i);
        }
    }

    // for(int i=1;i<=n;i++){
    //     cout<<next[i]-prev[i]-1<<" ";
    // }

    int ans[n + 1] = {};   //taking a ans array with all elements initialized to 0
    for (int i = 1; i <= n; i++)
    {
        int x = next[i] - prev[i] - 1;      //Span of the range in which current element is minimum
        ans[x] = max(ans[x], height[i]);       //storing the element at index=range of thar element
    }   
    for (int i = n - 1; i > 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);       //Suffix Max 
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
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



/*Question
Description

There are N soldiers standing in a row, numbered 1 through N. The height of i-th soldier is Hi. 
For each non-empty contiguous segment of the line, strength is defined as the minimum height of the soldier in that segment.
You have to tell the maximum strength for each x size group, for all groups of size x between 1 to N.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the length of the array.
The second line of each test case contains N space-separated integers - H1, H2, ... HN, heights of soldiers.


Output Format

For each test case, print N integers in one line. For each x from 1 to N, print the maximum strength among all groups of size x.


Constraints

1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ Hi ≤ 109
Sum of N over all test cases doesn't exceed 5 x 105


Sample Input 1

3
3
1 5 3
4
8 6 1 1
7
1 2 3 4 6 3 2

Sample Output 1
5 3 1
8 6 1 1
6 4 3 3 2 2 1

Note

In the first test case of the example, for x=1, possible answers are 1, 5 and 3 (maximum of them is 5).
For x=2, possible answers are 1 and 3 (maximum of them is 3)
For x=3, the only possible answer is 1.

In the second test case of the example, for x=1, possible answers are 1, 6 and 8 (maximum of them is 8).
For x=2, possible answers are 1 and 6 (maximum of them is 6)
For x=3 and x=4, the only possible answer is 1.
*/


//----------------------------------------------------------------------------------------------------------------


/* SOlution
For each i, find the largest j that aj < ai and j < i (if there is no such j, then consider it as -1).
Let this be Li. Similarly, find the smallest j that aj < ai and j > i (if there is no such j, then consider it as N). Let this be Ri.
You can use the stack for doing this in O(N). For each i, we know that it can be the minimum element in groups of size 1, 2, ..., ri - li - 1.
Let ansi be the answer of i from 0 to N-1, then ans1 ≥ ans2 ≥ ... ≥ ansN.

See Solution code.

Time Complexity: O(N)


For the last part of Code's explaination:

A[i] is max in the range r[i]-1 to l[i]+1.

So there is a range of length x, possible with max. = a[i].

Ans[x] = means what is the max possible Value that is possible for x length window.

Now in the next loop, we are doing a suffix max.
Basically saying that if there is a X length with max = a[i], then there is also a length X-1 window with max = a[i].*/