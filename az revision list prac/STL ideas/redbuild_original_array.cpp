/*Question
Your class teacher wrote N integers on the board. One of your classmates was being mischievous, 
he replaced the N integers with all possible subset sums of the array when the teacher was not in the class.
Suppose that the integers on the board were [2,1] then the subsets will be: {}, {2}, {1}, {2,1} and the subset sums will be: {0,2,1,3}.
Your task is to rebuild the original array given by your teacher.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the number of elements in the initial array.
The second line of each test case contains 2N space-separated integers, the new values on the board.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    multiset<int>allnum;

    for(int i=0;i<(1<<n);i++){
        int x; cin>>x;
        allnum.insert(x);
    }

    vector<int>generated;
    generated.push_back(0);
    allnum.erase(allnum.find(0));
    vector<int>orig;

    while(!allnum.empty()){
        int smaller= *allnum.begin();
        vector<int>newgen;
        orig.push_back(smaller);
        for(auto v: generated){           //we can also use it like for(auto &v :generated) , it will be a lttle faster as we dont change any values so no need of a copy
            newgen.push_back(smaller+v);
        }

        for(auto v:newgen){
            generated.push_back(v);
            allnum.erase(allnum.find(v));
        }

    }
    for(auto v:orig){
        cout<<v<<" ";
    }
    cout<<'\n';
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}

/* Solution
The original array has non-negative integers. At each step, we have to take the smallest integer.
We can use multiset for this problem. At each step, when an element x[i] is added to the original array, 
you have to erase all sums formed by x[i] and non-empty subsets of {x[1], x[2], …, x[i – 1]} from the multiset.

Time Complexity: O(N*2N)*/