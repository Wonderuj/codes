/* Question
You have a rectangular sheet of paper with dimensions H x W. You make N horizontal and verticals cuts in the sheet. Find the area of the maximum fragment after each cut.

It is guaranteed that there won't be any two identical cuts. Also, The cut that you make in the previous queries persists on the paper for the next queries.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains three space-separated integers H W N - the dimensions of the sheet and the number of cuts.

Each of the next N lines is of the form H Y or V X. For H Y, you make a horizontal cut at distance Y from the lower edge of the sheet and for V X, you make a vertical cut at a distance X from the left edges of the sheet.


Output Format

For each test case, print the area of the maximum fragment after each cut.*/
//----------------
/*Solution Approach
The largest piece would have the largest height and width.

Store all the height and width in two multisets. Also store all the horizontal and vertical cut marks in separate sets.

Time Complexity per test case: O(N * log(W + H))*/

#include <bits/stdc++.h>
using namespace std;
//#define int long long
void solve()
{
    int h, w, n;
    cin >> h >> w >> n;
    multiset<int> hseg, wseg, hcut, wcut;
    hcut.insert({0, h});
    wcut.insert({0, w});
    hseg.insert(h);
    wseg.insert(w);

    for (int i = 0; i < n; i++)
    {
        int x;
        char a;
        cin >> a >> x;
        if (a == 'H')
        {
            hcut.insert(x);
            auto left = hcut.find(x);
            auto right = hcut.find(x);
            left--;
            right++;

            int to_erase = (*right-*left);
            hseg.erase(hseg.find(to_erase));
            int to_insert1 = (x - *(left));
            int to_insert2 = ((*right) - (x));
            hseg.insert({to_insert1, to_insert2});
        }

        else{
            wcut.insert(x);
            auto left = wcut.find(x);
            auto right = wcut.find(x);
            left--;
            right++;

            int to_erase = (*right - *left);
            wseg.erase(wseg.find(to_erase));
            int to_insert1 = (x - *(left));
            int to_insert2 = ((*right) - (x));
            wseg.insert({to_insert1, to_insert2});
        }

        cout<< 1ll* (*wseg.rbegin() ) * (*hseg.rbegin())<<'\n';
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