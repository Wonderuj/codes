// #include <bits/stdc++.h>
// using namespace std;
// int n, m;

// vector<vector<int>> g;
// vector<int> indeg;
// // vector<int> outdeg;

// vector<int> topo;
// void kahn()
// {
//     queue<int> q;
//     for (int i = 1; i <= n; i++)
//     {
//         if (indeg[i] == 0)
//             q.push(i);
//     }
//     while (!q.empty())
//     {
//         int cur = q.front();
//         q.pop();
//         topo.push_back(cur);
//         for (auto v : g[cur])
//         {
//             indeg[v]--; // indegree of the current nodes neighbour is decreased by one. it acts as if we are removing the node from graph.
//             if (indeg[v] == 0)
//                 q.push(v);
//         }
//     }
// }
// void solve()
// {
//     cin >> n >> m;
//     g.resize(n + 1);
//     indeg.assign(n + 1, 0);
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         indeg[b]++;
//         // outdeg[a]++ if we wanted to save out degrees of nodes
//     }
//     kahn();
//     if (topo.size() != n)
//     {
//         cout << "Theres a cycle\n";
//     }
//     else
//     {
//         for (auto v : topo)
//         {
//             cout << v << " ";
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

// to find if theres a cycle in directed graphs or not, we just add one line that size of topo is n is not. If there was a cycle, there will be no edge afteer some point
// whose indegree would be zero, that is nothing will be added to the queue after that, so topo vector will not have n elements.

//-------------------------
//to find lexiographically smallest topo ordering, just use priority queue instead of queue. insert negative numbers that will give min number from pq.top()

#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>g;
vector<int> topo, indeg;

void kahn(){
    priority_queue<int>pq;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            pq.push(-i);
        }
    }
    while(!pq.empty()){
        int cur=-pq.top();
        pq.pop();
        topo.push_back(cur);
        for(auto v:g[cur]){
            indeg[v]--;
            if(indeg[v]==0){
                pq.push(-v);
            }
        }
    }

}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    indeg.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
    }
    kahn();
    if(topo.size()!=n){
        cout<<"theres a cycle\n";
    }
    else{
        for(auto v:topo){
            cout<<v<<" "; 
        }
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}

/*
5 5
4 3
4 2
3 1
2 1
2 5
ans- 4 2 3 1 5 */