#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    stack<int> st;

    int op = 0;

    if (n == 1)
    {
        cout << "0\n";
        return;
    }

    else if (n <= k)
    {
        cout << "1\n";
        return;
    }
   
    for (int i = 0; i < n; i++)
    {
        st.push(1);
    }
    
    while (st.size() > 1)
    {
        int x = st.top();
        st.pop();
        for (int i = 1; i < k; i++)
        {
            x += st.top();
            st.pop();
        }
        op++;
        st.push(x);
    }
    cout << op << endl;
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