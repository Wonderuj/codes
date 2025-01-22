
// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;
//     int t = 1000100;
//     vector<bool> isprime(t, true);

//     for (int i = 2; i * i < t; i++)

//     {
//         if (!isprime[i])
//             continue;
//         for (int j = i + i; j < t; j += i)
//         {
//             isprime[j] = false;
//         }
//     }

//     for (int i = 4; i < n; i++)
//     {
//         if (isprime[i] or isprime[n - i])
//             continue;
//         else
//         {
//             cout << i << " " << n - i;
//             return;
//         }
//     }
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }


//NO need to do all this , we can have a simpler solution. if the number is even the first composite even number is 4, other will be n-4.
// when n= odd , then first composite odd is 9 and its counter would be n-9 and for min case, n=13 the numbers will be 9 and 4.
