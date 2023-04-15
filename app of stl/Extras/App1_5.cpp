// // stl application 1.5
// O(n^2)
// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     long long ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int minval = INT_MAX;
//         for (int j = i; j < n; j++)
//         {
//             minval = min(minval, arr[j]);
//             ans += minval;
//         }
//     }
//     cout << ans << endl;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int t = 1;
//     // cin>>t;
//     for (int i = 0; i < t; i++)
//     {
//         solve();
//     }
// }

// -------------------------------------------------------------------------------
//There are 2 ways to make this code. one is using stacks and other is not.
// vector<int> next_smaller(vector<int> arr)
// {
//     int n = arr.size();
//     vector<int> next_sm(n);

//     stack<int> st;

//     for (int i = n - 1; i >= 0; i--)
//     {
//         while (!st.empty())
//         {
//             int indx = st.top();
//             if (arr[i] <= arr[indx])
//             {
//                 st.pop();
//             }
//             else
//             {
//                 next_sm[i] = st.top();
//                 break;
//             }
//         }
//         if (st.empty())
//         {
//             next_sm[i] = n;
//         }
//         st.push(i);
//     }
//     return next_sm;
// }
// -------------- The other way------------------------------
// vector<int> next_smaller_2(vector<int> arr)
// { // O(N)
//     int n = arr.size();
//     vector<int> next_sm(n);

//     for (int i = n - 1; i >= 0; i--)
//     {
//         next_sm[i] = i + 1;
//         while (next_sm[i] != n && arr[i] <= arr[next_sm[i]])
//         {
//             next_sm[i] = next_sm[next_sm[i]];
//         }
//     }

//     return next_sm;
// }
//-------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
vector<int> next_smaller(vector<int> arr)
{
    int n = arr.size();
    vector<int> sm(n);
    for (int i = n - 1; i >= 0; i--)
    {
        sm[i] = i + 1;
        while (sm[i] != n && arr[i] <= arr[sm[i]])
        {
            sm[i] = sm[sm[i]];
        }
    }
    return sm;
}
vector<int> prev_smaller(vector<int> arr)
{
    int n = arr.size();
    vector<int> prev_sm(n);
    for (int i = 0; i < n; i++)
    {
        prev_sm[i] = i - 1;
        while (prev_sm[i] != -1 && arr[i] < arr[prev_sm[i]])
        {
            prev_sm[i] = prev_sm[prev_sm[i]];
        }
    }
    return prev_sm;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    auto nxt = next_smaller(v);
    auto prev = prev_smaller(v);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += v[i] * ((nxt[i] - 1) * (1 - prev[i]));
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}