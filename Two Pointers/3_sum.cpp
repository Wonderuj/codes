#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (auto &v : arr)
    {
        cin >> v;
    }

    int diff = LLONG_MAX; // need to minimize the difference
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int first = arr[i];
        int tail = arr.size()-1, head = i + 1;

        while (head < tail)
        {
            if (first + arr[head] + arr[tail] == target)
            {
                diff=0;
                return;
            }
            else if (abs(first + arr[head] + arr[tail] - target) < diff)
            {
                diff = abs(first + arr[head] + arr[tail] - target);
            }

            if (first + arr[head] + arr[tail] > target)
                tail--;
            else
                head++;
        }
    }
    cout << diff << endl;
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
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (auto &v : arr)
    {
        cin >> v;
    }

    int diff = LLONG_MAX; // need to minimize the difference
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int first = arr[i];
        int tail = arr.size()-1, head = i + 1;

        while (head < tail)
        {
            if (first + arr[head] + arr[tail] == target)
            {
                diff=0;
                return;
            }
            else if (abs(first + arr[head] + arr[tail] - target) < diff)
            {
                diff = abs(first + arr[head] + arr[tail] - target);
            }

            if (first + arr[head] + arr[tail] > target)
                tail--;
            else
                head++;
        }
    }
    cout << diff << endl;
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