/*QUESTION
Description

Given two binary numbers as strings, return their binary sum as a string.

Input Format

Two lines contain a binary string, |S| ≤ 10^6.

Output Format

Print the binary sum of two binary strings.

Sample Input 1
111
1

Sample Output 1
1000
*/

// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     string s1, s2;
//     cin >> s1 >> s2;
//     int n = max(s1.length(), s2.length());
//     reverse(s1.begin(), s1.end());
//     reverse(s2.begin(), s2.end());
//     string res;
//     int carry = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int digitA = i < s1.length() ? s1[i] - '0' : 0;
//         int digitB = i < s2.length() ? s2[i] - '0' : 0;

//         int total = digitA + digitB + carry;
//         char a = total % 2 + '0'; // total can be 0 1 2 or 3. so when its 3 we need 1 and when its 2 we need 0 to be
//         // cout<<a<<" a "<<endl;
//         res.push_back(a);
//         carry = total / 2;
//     }

//     if (carry)
//     {
//         res.push_back(1);
//     }
//     reverse(res.begin(), res.end());
//     cout << res << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;

    int n1 = s1.length();
    int n2 = s2.length();
    int n = max(n1, n2);

    int carry = 0;
    string res;
    int i = n1 - 1, j = n2 - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int digitA = (i >= 0) ? s1[i] - '0' : 0;
        int digitB = (j >= 0) ? s2[j] - '0' : 0;

        int total = digitA + digitB + carry;
        char a = total % 2 + '0';
        res.push_back(a);      //for strings dont do res=a+res; as whole string gets copied and gives TLE
        carry = total / 2;

        i--;
        j--;
    }
    reverse(res.begin(),res.end());
    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}
