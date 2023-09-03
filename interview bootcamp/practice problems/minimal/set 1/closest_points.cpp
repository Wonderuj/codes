/*Question
Given coordinates of the N points, find the K closest point to the origin. Print the points in order -

The closest point to the origin first.
If the distance is the same, then one with the smallest ‘X coordinate.

Input Format

The first line contains two space-separated integers N, K (1 ≤ K ≤ N ≤ 10^6).
The next N lines contain Coordinates of the points (1 ≤ X, Y ≤ 10^5).
Try to do it in NlogK. In the actual interview after NlogN solution, you will have to optimize it further to NlogK solution.

Output Format

Print K closest points in the order mentioned in the statement.

Sample Input 1

5 3
1 5
7 8
8 1
1 6
2 4

Sample Output 1

2 4
1 5
1 6
*/

#include <bits/stdc++.h>
using namespace std;
// #define int long long
void solve()
{
    int n, k;
    cin >> n >> k;
    priority_queue<pair<long long, pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        long long dis = x * x + y * y;

        if (pq.empty() || pq.size() < k)
        {
            pq.push({dis, {x, y}});
        }
        else if (!pq.empty() && pq.top().first >= dis)
        {
            pq.pop();
            pq.push({dis, {x, y}});
        }
    }
    vector<pair<long long, pair<int, int>>> temp;
    while (!pq.empty())
    {
        temp.push_back(pq.top());
        pq.pop();
    }
    reverse(temp.begin(), temp.end());
    for (auto x : temp)
    {
        cout << x.second.first << " " << x.second.second << '\n';
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