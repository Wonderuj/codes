#include <bits/stdc++.h>
using namespace std;

int n;
int sum;
string s;
bool valid(int sum)
{
    return (sum >= 0);
}
void rec(int level)
{ // level is n
    // base case
    if (level == n)
    {
        if (sum == 0)
        {
            cout << s << '\n';
        }
        return;
    }

    // recursion
    s += '(';
    sum++;
    if (valid(sum))
    {
        rec(level + 1);
    }
    sum--;
    s.pop_back();
    //trying the other bracket
    s += ')';
    sum--;
    if (valid(sum))
    {
        rec(level + 1);
    }
    sum++;
    s.pop_back();
}
void solve()
{
    cin >> n;
    s="";
    sum=0;
    rec(0);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}
