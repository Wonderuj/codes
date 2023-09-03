/*Question
You have given an array A of size N. A1, A2, ..., AN are the elements of the array. All elements in the array A are distinct.
Find the sum of the minimum of all subarrays possible of array A.

A subarray of an -element array is an array composed from a contiguous block of the original array's elements


For each test case, print a single number representing the sum of the minimum of all subarrays of A.

Example:
1 2 3
Min{1} + Min{1, 2} + Min{1, 2, 3} + Min{2} + Min{2, 3} + Min{3} = 1 + 1 + 1 + 2 + 2 + 3 = 10
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int n;
    cin >> n;

    int v[n+2], left[n+2], right[n+2];
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i];
    }
    stack<int> st;
    v[0] = -1e9;
    v[n + 1] = -1e9;
    st.push(0);
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && v[st.top()] >= v[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            st.push(i);
            left[i]=i;
        }

        else
        {
            left[i]=st.top();
            st.push(i);
        }
    }

    // for (auto v : left)
    // {
    //     cout << v << " ";
    // }
    // cout<<endl;

    while (!st.empty())
    {
        st.pop();
    }

    st.push(n + 1);
    for (int i = n; i > 0; i--)
    {
        while (!st.empty() && v[st.top()] >= v[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            st.push(i);
            right[i] = i;
        }

        else
        {
            right[i]=(st.top());
            st.push(i);
        }
    }

    // for (auto v : right)
    // {
    //     cout << v << " ";
    // }

    ll ans = 0;

    for (int i = 1; i <= n; i++)
        ans += 1LL * v[i] * (i - left[i]) * (right[i] - i);

    cout << ans << "\n";
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

/*
We try to find the individual contribution of all elements in the array.
Suppose cnti is the number of subarrays with Ai is the minimum.
Then the answer will be the sum of all cnti * Ai. So now the question is how to find cnti?
Create a new array B by appending -INF at the beginning and end of the array A.
B = {-INF, A1, A2, ..., AN, -INF}.
Now for newly constructed array B find the next smaller and the previous smaller for each element Bi s.t. 2 ≤ i ≤ N+1 (assuming array to be 1-index).
Let ni and pi be the index of next smaller and previous smaller of element Bi, s.t. 2 ≤ i ≤ N+1.
Now all the subarrays [start, end] with start ∈ {pi + 1, i} and end ∈ {i, ni - 1} has minimum value of Bi.
That means, the contribution of Bi in total sum is (i - pi) * (ni - i).
So the final answer is the sum of the contribution of all Bis. (Note that we are only considering 2 ≤ i ≤ N+1.)
We can find the next smaller and previous smaller in O(N) using stack.

Time complexity: O(N)
Space complexity: O(N)
*/