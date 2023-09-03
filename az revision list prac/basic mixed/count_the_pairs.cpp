/*Question
You are given an array A of size N. You need to find the number of pairs (i, j) , i!= j, such that A[i]+A[j] ≤ X.
*/

/* Solution
Use upper_bound to find the number of elements satisfying A[j]≤X−A[i]

Time Complexity per test case: Sorting take O(NlogN)
Solution 2
Using 2 pointer type approach.
We initialize two pointers, i and j, that point to the first and last elements of the array, respectively.
In each iteration of the while loop, we check if the sum of the elements pointed by i and j is less than or equal to x.
If yes, we add the number of pairs that sum up to a value less than or equal to x by incrementing the count cnt by 2×(j−i) and incrementing i by 1.
If the sum of the elements pointed by i and j is greater than x, we decrement j by 1 as all the pairs with a higher sum would also be greater than x.
Repeat the process until i becomes greater than or equal to j.
Finally, we print the value of cnt, which is the number of pairs that sum up to a value less than or equal to x.

Time Complexity per test case: Sorting takes O(NlogN)*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, x;
int arr[100100];
void solve()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int st = 0;
    int end = n - 1;
    int count = 0;
    sort(arr, arr + n);
    while (st < end)
    {
        if (arr[st] + arr[end] > x)
        {
            end--;
        }
        else
        {
            count += (end - st) * 2;
            st++;
        }
    }
    cout << count << endl;
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



//upperbound

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// void solve()
// {
//     int n, x;
//     cin >> n >> x;
//     vector<int> v(n);
//     for (auto &i : v)
//     {
//         cin >> i;
//     }
//     sort(v.begin(), v.end());
//     int count = 0;
//     for (int a : v)
//     {
//         count += upper_bound(v.begin(), v.end(), x - a) - v.begin();
//         if (x - a >= a)
//             count--;
//     }
//     cout << count << "\n";
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