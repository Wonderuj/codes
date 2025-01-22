#include <bits/stdc++.h>
using namespace std;

bool check(int n, vector<int> &a)
{
    string s;
    cin >> s;
    map<char, int> mp;

    if (s.length() != a.size())
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        if (mp.find(s[i]) != mp.end())
        {
            if (mp[s[i]] != a[i])
            {
                return false;
            }
        }
        else
        {
            mp[s[i]] = a[i];
        }
    }

    map<int, char> temp;
    for (int i = 0; i < n; i++)
    {
        if (temp.find(a[i]) != temp.end())
        {
            // cout << "found " << a[i] << " - " << s[i] << endl;
            if (temp[a[i]] != s[i])
            {
                return false;
            }
        }
        else
        {
            // cout<<"inserting "<<a[i] <<" - "<<s[i]<<endl;
            temp[a[i]] = s[i];

        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++)
    {
        
        cin >> a[i];
    }
    int m;
    cin >> m;
    while (m--)
    {
        if (check(n, a))
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
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