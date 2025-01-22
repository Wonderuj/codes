// #include <bits/stdc++.h>
// using namespace std;

// struct UnionFind
// {
//     int n, set_size, *parent, *rank;
//     UnionFind() {}
//     UnionFind(int a)
//     {
//         n = set_size = a;
//         parent = new int[n + 1];
//         rank = new int[n + 1];
//         for (int i = 1; i <= n; i++)
//         {
//             parent[i] = i;
//             rank[i] = 1; // each of elements rank initiallly is n+1
//         }
//     }
//     int find(int x)
//     {
//         if (x != parent[x])
//         {                                       // if x isnt a representative element
//             return parent[x] = find(parent[x]); // find parent of x and when you comeback update the value in parent array
//         }
//         return x;
//     }

//     void merge(int x, int y)
//     {
//         int xroot = find(x), yroot = find(y);
//         if (xroot != yroot) // nodes in different components
//         {

//             if (rank[xroot] >= rank[yroot]) // if size of y subtree is less merge Y in X
//             {
//                 rank[xroot] += rank[yroot];
//                 parent[yroot] = xroot;
//             }
//             else
//             {
//                 rank[yroot] += rank[xroot];
//                 parent[xroot] = yroot;
//             }
//             set_size -= 1; // we merged 2 nodes so number of components(set_size) decreases by 1
//         }
//     }

//     void reset()  //just to reset to initial values
//     {
//         set_size = n;
//         for (int i = 1; i <= n; i++)
//         {
//             parent[i] = i;
//             rank[i] = 1;
//         }
//     }

//     int size()
//     {
//         return set_size;
//     }
//     void print()
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             cout << i << " -> " << parent[i] << '\n';
//         }
//     }
// };

// void solve()
// {
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // int _t; cin>>_t;while(_t--)
//     solve();
// }


//------------------------------------------------------- Practicing again  ----------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    int n, set_size, *parent, *rank;

    UnionFind(){};
    UnionFind(int a)
    {
        n = a;
        set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if (x != parent[x])
        {
            return parent[x] = find(parent[x]);
        }
        return x;
    }

    void merge(int x, int y)
    {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot != yroot)
        {
            if (rank[xroot] >= rank[yroot])
            {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else
            {
                parent[xroot] =yroot;
                rank[yroot] += rank[xroot];
            }
            set_size -= 1;
        }
    }

    void reset()
    {
        set_size = n;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int size()
    {
        return set_size;
    }

    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " -> " << parent[i] << '\n';
        }
    }
};

void solve()
{
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}