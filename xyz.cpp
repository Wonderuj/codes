#include <bits/stdc++.h>
using namespace std;

int minimumSum(vector<int> &nums)
{
    int n = nums.size();
    int left[n];
    int right[n];

    int mini = 1e9;

    for (int i = 0; i < n; i++)
    {
        if (mini == 1e9)
        {
            left[i] = -1;
        }
        else
        {
            if (nums[i] > mini)
                left[i] = mini;
            else
                left[i] = -1;
        }
        mini = min(mini, nums[i]);
    }
    cout << "nums ";
    for (auto x : nums)
        cout << " " << x;
    cout << endl;

    cout << "left ";
    for (auto x : left)
        cout << " " << x;
    cout << endl;
    mini = 1e9;

    for (int i = n - 1; i >= 0; i--)
    {
        if (mini == 1e9)
        {
            right[i] = -1;
        }
        else
        {
            if (nums[i] > mini)
                right[i] = mini;
            else
                right[i] = -1;
        }
        mini = min(mini, nums[i]);
    }

    cout << "right ";
    for (auto x : right)
        cout << " " << x;
    cout << endl;

    int ans = 1e9;
    
    for (int i = 0; i < n; i++)
    {
        if (left[i] != -1 && right[i] != -1)
        {
            ans = min(ans, nums[i] + left[i] + right[i]);
        }
        cout << ans<<" ";
    }
    cout<<endl;
    if (ans == 1e9)
        return -1;
    return ans;
}

void solve()
{
    vector<int> arr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        arr.push_back(c);
    }
    cout << minimumSum(arr) << endl;
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
6
5 4 8 7 10 2
*/