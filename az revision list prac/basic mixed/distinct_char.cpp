/*
You are given a string S. You are given Q queries of two types, 
asking the number of distinct characters in the range [L, R] and changing the i-th character to c. (1-based indexing)

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test contains a string S.
The second line of each test case contains one integer Q - the number of queries.

Each of the next Q lines contain two types of queries: either 1 i c or 2 L R. 
The query 1 is for changing the i-th character to c and the query 2 is for finding the number of distinct characters in the range [L, R].*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int q;
    cin >> q;
    bool arr[26];           //boolean array will help me to check if that char is present or not by 0/1
    
    while (q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int x;
            char c;
            cin >> x >> c;
            s[x - 1] = c;       //changing ith char to c acc to question
        }

        else
        {
            for (int i = 0; i < 26; i++)
            {   
                arr[i] = 0;             //making all the blocks as 0
            }
            int count = 0;
            int l, r;
            cin >> l >> r;
            for (int i = l - 1; i < r; i++)
            {
                int pos = s[i] - 'a';   //finding which char is on the string
                if (!arr[pos])
                {
                    arr[pos] = 1;           //if it was 0 (that means we didnt ecountered it before, so make it 1 so as to mark it found)
                }
            }
            for (int i = 0; i < 26; i++)
            {
                if (arr[i])
                {
                    count++;        //check how many char are found
                }
            }
            cout << count << endl;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;
    cin >> _t;
    string temp;
    getline(cin, temp);
    while (_t--)
        solve();
}

