#include <bits/stdc++.h>
using namespace std;

void solve1()
{
    int n;
    cin >> n;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int abcde, fghij;
    do
    {
        // for(auto v:arr){            //these 3 lines are use to print all the permutations of this number.
        //     cout<<v<<" ";
        // } cout<<endl;
        abcde = arr[0] * 10000 + arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[4];
        fghij = arr[0 + 5] * 10000 + arr[1 + 5] * 1000 + arr[2 + 5] * 100 + arr[3 + 5] * 10 + arr[4 + 5];
        if (abcde % fghij == 0)
        {
            if (abcde / fghij == n)
            {
                cout << abcde << " " << fghij << endl;
            }
        }
    } while (next_permutation(arr.begin(), arr.end()));
}

void solve2()
{
    int n;
    cin >> n;
    for (int fghij = 1234; fghij <= 98765 / n; fghij++)
    {
        int abcde = n * fghij;
        set<int> st;

        int temp = abcde;
        for (int i = 0; i < 5; i++)
        {
            st.insert(temp % 10); // take number abcde and for 5 times insert its remainder with 10(this inserts last digit)
            temp /= 10;           // and then divide number by 10 so last number will be removed
        }

        temp = fghij;
        for (int i = 0; i < 5; i++)
        {
            st.insert(temp % 10); // take number fghij and for 5 times insert its remainder with 10(this inserts last digit)
            temp /= 10;           // and then divide number by 10 so last number will be removed
        }
        if (st.size() == 10)
        { // checking if all numbers are distinct
            cout << abcde << " " << fghij << endl;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve2();
}