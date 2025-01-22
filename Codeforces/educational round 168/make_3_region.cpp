// #include <bits/stdc++.h>
// using namespace std;

// int n;

// bool check_free(int x, int y, vector<string> &s)
// {
//     char c = s[x][y];
//     if (y == 0 or y == n - 1 or c == 'x')
//         return false;

//     if (x == 0)
//     {
//         if (s[x][y - 1] == '.' and s[x][y + 1] == '.' and s[x + 1][y] == '.')
//             return true;
//     }
//     else if (x == 1)
//     {
//         if (s[x][y - 1] == '.' and s[x][y + 1] == '.' and s[x - 1][y] == '.')
//             return true;
//     }
//     return false;
// }

// void solve()
// {
//     cin >> n;
//     vector<string> s(2);
//     for (auto &x : s)
//         cin >> x;
//     int ans = 0;

//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {

//             if (check_free(i, j, s))
//             {
//                 cout << "hit: " << i << " " << j << endl;
//                 ans++;
//             }
//         }
//     }
//     cout << ans << '\n';
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int _t;
//     cin >> _t;
//     while (_t--)
//         solve();
// }


#include<bits/stdc++.h>
using namespace std;

void solve(){
     int N;cin>>N;
        string A,B;cin>>A>>B;
        int ans=0;
        for(int q=0;q<2;q++){
            for(int i=1;i<N-1;i++){
                if(A[i]=='.'&&B[i]=='.'&&B[i-1]=='x'&&B[i+1]=='x'&&A[i-1]=='.'&&A[i+1]=='.') ans++;
            }
            swap(A,B);
        }
        cout<<ans<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}