/* Question
Design a Data Structure which can support the following queries:

Initially, the structure is empty. You have given an integer K.

The structure is arranged in the order from greater elements to smaller elements. So when we say top K elements, we mean the top K largest elements.

1 x: Add x in structure.

2 x: Remove x from the structure if present in the structure. If x doesn't present in the structure, do nothing. If there are multiple occurrences of x, delete only one occurrence of x.

3 ?: Print the sum of the top K elements. If the structure contains less than K elements, then print the sum of all elements present in the structure. If the structure is empty, then print 0.
*/


#include <bits/stdc++.h>
using namespace std;
int K;
struct datastr
{
    int k = K;
    multiset<int> large, small;
    int sum = 0;

    void add(int x)
    {
       
        large.insert(x);
        sum += x;
       
        if (large.size() > k)
        {
            int temp = *large.begin();
            sum = sum- temp;
            //cout<<" sum "<<sum<<endl;
            large.erase(large.find(temp));
            small.insert(temp);
        }
        return;
    }

    void remove(int x)
    {
        if (large.empty())
        {
            return;
        }

        if (!large.empty() && large.find(x) != large.end())
        {
            large.erase(large.find(x));
            sum -= x;
            if (large.size() < k && !small.empty())
            {
                int temp = *small.rbegin();
                large.insert(temp);
                sum += temp;
                small.erase(small.find(temp));
            }
        }

        else
        {
            // if (!small.empty())
            // {
            //     return;
            // }
            if (!small.empty() && small.find(x) != small.end())
            {
                small.erase(small.find(x));
            }
        }

        return;
    }

    int topk()
    {
        return sum;
    }
};
void solve()
{
    int q;
    cin >> q >> K;
    datastr ds;
    while (q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int x;
            cin >> x;
            ds.add(x);
        }
        else if (a == 2)
        {
            int x;
            cin >> x;
            ds.remove(x);
        }
        else if (a == 3)
        {
            char c;
            cin >> c;
            cout << ds.topk() << '\n';
        }
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

//-- -- -- -- -- -- -
/* Solution
Maintain two multisets, lets call them M1, M2. M1 multiset will store candidates elements for top K positions, i.e., greatest K elements. M2 will store other remaining elements.
Note that at any point, it may be possible that both M1 and M2 are empty, or both M1 and M2 are non-empty, or M1 is non-empty and M2 is empty.

When add query comes, the following scenarios can possible to happen.

If the size of M1 is less than K, then add that element in M1.
If the current size of M1 is equal to K, add the element in M1 and remove the smallest element in M1 and add that element in M2.
When remove query comes, the following scenarios can possible to happen.

If the query element x is present in M2, remove it directly from M2.
If the query element x is present in M1, remove it from M1. And
if the size of M1 is equal to K - 1 and M2 is non-empty, the remove greatest element from M2 and add that in M1. If M2 is empty, that means so far we have  - 1 element present in the structure.
if the size of M1 is less than K - 1, that M2 is empty.*/