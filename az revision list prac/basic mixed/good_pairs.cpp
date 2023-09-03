/*You are given two arrays A and B, both of size N. A pair is called good if i < j and Ai + Aj > Bi + Bj. Find the number of good pairs.*/

/*
Store all the values of Ai - Bi in a vector and sort it.
A question that might arise is how we can allow ourselves to sort the vector since the constraint i<j is clearly mentioned in the problem. 
Sorting a vector results in the loss of information about the original indices of the elements, making it difficult to determine the original order of the elements.

When we want to find pairs in a vector such that their sum is greater than 0, 
we can use the fact that addition is a commutative operation, which means that the order in which we add the elements doesn't matter. 
For example, 2 + 3  is the same as 3 + 2 .

Now, let's say we have a vector C and we want to find pairs ( i , j )  such that C i + C j > 0 . 
We can sort the vector in non-decreasing order, which means that the smallest element will be first and the largest element will be last. 
Once the vector is sorted, we can start with the smallest element and add it to the largest element. If the sum is greater than 0 , 
then we know that all pairs involving the largest element will satisfy the condition as well, 
because any pair with a smaller element than the largest element will have a sum that is even smaller than the sum we just computed.

At no point during this process do we need to worry about losing track of the original indices of the elements, 
because we can always interchange the indices of any two elements in a pair. For example, if we find a pair ( i , j )  where i > j , 
we can simply swap i  and j  to get the pair ( j , i ) . 
This means that even if we sort the vector, we can still consider all possible pairs and find the ones that satisfy the condition C i + C j > 0
.
complexity- O(N Log N)*/

#include <bits/stdc++.h> 
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] -= x;                     //Making (Ai-Bi) in a single vector itself
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)                                            //if the current element is negative then,
        {
            auto it = upper_bound(arr.begin(), arr.end(), -arr[i]);       //I need Ci+Cj>0 so Cj>Ci , we can find that using upper bound
            if (it!=arr.end())                                      //if Upper bound exits,
            {                   
                cnt += n - (it - arr.begin());                    //all elements from upper bound till end are valid
            }
        }
        else
        { // if current was positive , we can simply say all elemets after it are valid as sum will simply get larger and larger in sorted array
            cnt += n - (i + 1);
        }
    }
    cout << cnt << '\n';
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

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// void solve()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         arr[i] -= x;
//     }
//     sort(arr, arr + n);
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] <= 0)
//         {
//             auto it = upper_bound(arr, arr + n, -arr[i]);
//             if (it != arr+n)
//             {
//                 cnt += n - (it - arr);
//             }
//         }
//         else
//         {
//             cnt +=n-(i+1);
//         }
//     }
//     cout<<cnt<<'\n';
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