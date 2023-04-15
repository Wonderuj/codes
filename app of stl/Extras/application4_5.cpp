// #include<bits/stdc++.h>
// using namespace std;
// struct topk{
//     priority_queue<int>pq;
//     int k;
//     int sum;
//     //int k;
//     void init(int K){
//         sum=0;                                      //to flush out the garbage value created while declaring the struct in void below
//         k=K;                            
//         //this->k=k
//     }
//     int insert(int x){
//         sum+=x;
//         pq.push(-x);
//         if(int(pq.size())>k){
//             sum+=pq.top();
//             pq.pop();
//         }
//     }
//     int gettopk(){
//         return sum;
//     }
// };
// void solve(){
//     topk myDS;
//     myDS.init(3);
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }

//---------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
struct topk{
    int sum;
    multiset<int> larger,smaller;
    int k;
    void init(int K){
        sum =0;
        k=K;
    }
    void insert(int x){
        larger.insert(x);
        sum+=x;
        if(larger.size()>k){
            int temp=*larger.begin();
            sum-=temp;
            larger.erase(larger.find(temp));
            smaller.insert(temp);
        }
    }
    void remove(int x){
        if(larger.find(x)!=larger.end()){
            larger.erase(larger.find(x));
            sum-=x;
        }
        else if (smaller.find(x) != smaller.end()){
            smaller.erase(smaller.find(x));
        }
        if(larger.size()<k && !smaller.empty()){
            int temp= *smaller.rbegin();
            smaller.erase(smaller.find(temp));
            larger.insert(temp);
            sum+=temp;
        }
    }
    int getSum(){
        return sum;
    }
};
void solve(){

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}