#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int q;
    cin >> q;
    set<int> s, ns;
    while (q--)
    {
        int k, x;
        cin >> k >> x;
        if (k == 1)
        {
            s.insert(x);
            ns.erase(x);
            if (!s.count(x + 1))
            {
                ns.insert(x + 1);
            }
        }
        else
        {
            if (!s.count(x))
            {
                cout << x << endl;
            }
            else
            {
                cout << *ns.lower_bound(x) << endl;
            }
        }
    }
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

// question
/*
Description

You have an empty set and can perform the following operations on it:

1 x - Add integer x to the set
2 x - Find the smallest integer that is not present in the set, which is greater than or equal to x.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q lines contain two space-separated integers ti and xi - type and value of the query.


Output Format

For each test case, print the answer for the queries.


Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ ti ≤ 2

1≤ xi ≤ 1012

It is guaranteed that the sum of Q over all test cases does not exceed 106.


Sample Input 1

2
4
1 1
1 3
2 1
2 4
3
2 4
1 4
2 4

Sample Output 1

2
4
4
5

Note

For the first test case, the set is [1, 3]. Value which is not present and is ≥ 1 is 2 and ≥ 4 is 4.

For the second test case, the value which is not present and is ≥ 4 is 4. Then set becomes [4]. Value which is not present and is ≥ 4 is 5 now.
*/

/*
Solution:
This solution uses two sets s and ns to maintain the values of
xi and xi+1, respectively. When we perform an operation of type 1 x, we insert x into s. If x+1 is not already in s, we also insert it into ns. 
If x+1 is already in s, we remove it from ns. This is because if xi+1 is already in the set, we do not need to keep track of it separately, 
since we know that xi is present in the set.

When we perform an operation of type 2 x, we check if x is in s. If it is not, 
we return x as the smallest integer not present in the set that is greater than or equal to x. 
If x is in s, we use the lower_bound function on ns to find the smallest integer in ns that is greater than or equal to x,
and return that as the answer.

The reason this solution works is because the values in s represent the integers that are present in the set, 
and the values in ns represent the integers that are not present in the set but have an immediate neighbor that is present in the set. 
This means that the smallest integer not present in the set that is greater than or equal to x will either be x itself (if x is not in the set), 
or the smallest value in ns that is greater than or equal to x (if x is in the set).

Time Complexity per test case:
O(Q log Q) because each operation takes O(log Q) time to perform (due to the use of sets and the lower_bound function).
*/