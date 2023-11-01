/*
Description

There are N students and ith student likes all numbers in the range [li ,ri ], both inclusive. A numberis good if it is liked by at least K students.
You are even Q queries. Each query consists of two numbers L, R. You have to find how many numbers in the range [L,R] is good.

Input Format

The first line of input contains three integers, N, K (1 ≤ K ≤ N ≤ 1000000), and Q (1 ≤ Q ≤ 1000000).
The next N lines contain two integers li and ri (1 ≤ li ≤ ri≤ 1000000), describing that the i-th student likes all the numbers [li,ri].
The next Q lines contain L and R, (1 ≤ L ≤ R ≤ 1000000).

Output Format

For each query print how many numbers in the range [L,R] is good in a new line.

Sample Input 1

10 3 10
1 5
2 7
3 9
1 5
3 8
4 10
7 10
8 8
5 5
6 7
1 5
3 8
4 9
3 10
2 6
3 9
7 7
5 5
8 8
3 7

Sample Output 1

4
6
6
7
5
7
1
1
1
5
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;

    int prefix[N];
    memset(prefix, 0, sizeof(prefix));
    int l, r;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        prefix[l] += 1;
        prefix[r + 1] -= 1;
    }

    for (int i = 1; i < N; i++)
    {
        prefix[i] += prefix[i - 1];
    }

    for (int i = 1; i < N; i++)
    {
        if (prefix[i] >= k)
            prefix[i] = 1;
        else
            prefix[i] = 0;
    }

    for (int i = 1; i < N; i++)
    {
        prefix[i] += prefix[i - 1];
    }

    int ll, rr;
    while (q--)
    {
        cin >> ll >> rr;
        cout << prefix[rr] - prefix[ll - 1] << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}

/*
We know that a student i likes all the numbers between li  and ri .
So the effect of that student on the likeness of all the numbers between li  and ri  is 1 . 
This is similar to adding + 1  to all the numbers in the range li  and ri . We can solve this using partial sums concept.
Make an array arr in which whenever we find a student likes numbers between l and r we take care of its contribution using partial sums as follows,
arr [ l ] + = 1 , arr [ r + 1 ] + = − 1 
After performing prefix sum on the partial sum array arr we can get a count of the number of students liking a numberi . arr [ i ] + = arr [ i − 1 ]
*/

/*
Now that we have got the number of students liking the number i , 
we can find which are good numbers and which are not by simply finding which number has been liked by K or greater than K number of students, 
If arr [ i ] >= k  then arr [ i ] = 1  which means it is a good number otherwise 0 . 
Now we have the array arr  which simply stores whether a number is good number or not. 
So if a number i  is good arr [ i ] = 1  else arr [ i ] = 0  and we are to find the number of good numbers in a range l  to r . 
Doesn't it seem familiar?? Well you are right! We need to find the prefix sum of this array arr  to find the number of good numbers in a range. 
After doing a prefix sum any index i gives the number of good numbers from the beginning of the array to the index i . 
So to find the number of good numbers between range l  and r  we can do, a n s = arr [ r ] − arr [ l − 1 ] 

Time complexity of this solution is O ( n + N + Q ) , where N is the maximum number r i , we take it to be around 1000005 ,
n  is the number of students and Q  is the number of queries.*/