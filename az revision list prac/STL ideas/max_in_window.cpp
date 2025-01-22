/*Question
You have given an array A of size N and a positive integer K (≤ N). A1, A2, ..., AN are the elements of the array.
Let Bi = max (Ai, Ai+1, ..., Ai+K-1), for 1 ≤ i ≤ N - K + 1.
Find Bi values for all is such that 1 ≤ i ≤ N - K + 1.
*/

/*
Create a Deque, Q of capacity K, that stores only useful elements of the current window of k elements.
An element is useful if it is in the current window and is greater than all other elements on the left side of it in the current window.
Process all array elements one by one and maintain Q to contain useful elements of the current window and these useful elements are maintained in sorted order.
The element at front of the Q is the largest and element at the rear of Q is the smallest of the current window.
Algorithm:

Create a deque to store K elements.
Run a loop and insert the first K elements in the deque. While inserting the element if the element at the back of the queue is smaller than the current element removes all those elements and then insert the element.
Now, run a loop from K to end of the array.
Print the front element of the array
Remove the element from the front of the queue if they are out of the current window.
Insert the next element in the deque. While inserting the element if the element at the back of the queue is smaller than the current element removes all those elements and then insert the element.
Print the maximum element of the last window.
Time complexity: O(N)
Space complexity: O(K) extra space.*/


#include<bits/stdc++.h>
using namespace std;

struct monotone_deque{
    deque<int>dq;
    void insert(int x){
        while(!dq.empty() && dq.back()<x){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void remove(int x){
        if(dq.front()==x)
        dq.pop_front();
    }
    int get_maxi(){
        return dq.front();
    }
};

void solve(){
    int n,k;
    cin>>n>>k;
    int v[100001];
    monotone_deque dq;

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    for(int i=0;i<n;i++){
        dq.insert(v[i]);
        if(i-k>=0){
            dq.remove(v[i-k]);
        }
    
        if(i>=k-1){
            cout<<dq.get_maxi()<<" ";
        }
    }
    cout<<'\n';


}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}