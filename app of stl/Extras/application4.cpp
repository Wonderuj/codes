#include<bits/stdc++.h>
using namespace std;
struct dashboard{
    //mean
    int sum=0;
    double count=0;
    //variance
    int sumsq=0;
    //mode
    map<int, int>freq;
    multiset<pair<int,int>>freq_order;
    //median
    multiset<int> low,high;
    void balance(){
        while(low.size()<high.size()){
            int x=*high.begin();
            high.erase(high.find(x));
            low.insert(x);
        }
        while (low.size() > high.size()+1)
        {
            int x = *low.rbegin();
            low.erase(low.find(x));
            high.insert(x);
        }
    }

    void insert(int x){
        count++;
        sum+=x;
        sumsq+=x*x ;
        // mode
        if (freq_order.find(make_pair(freq[x], x)) != freq_order.end())
        {
            freq_order.erase(freq_order.find(make_pair(freq[x], x)));
        }
        freq[x]++;
        freq_order.insert(make_pair(freq[x],x));

        //median
        if(low.empty()) low.insert(x);
        else if(x<=(*low.rbegin())){
            low.insert(x);
        } 
        else{
            high.insert(x);
        }
        balance();
    }
    void remove(int x){
        count--;
        sum-=x;
        sumsq-=x*x;
        // remove
        //  mode
        if (freq_order.find(make_pair(freq[x], x)) != freq_order.end())
        {
            freq_order.erase(freq_order.find(make_pair(freq[x], x)));
        }
        freq[x]--;
        if(freq[x]) freq_order.insert(make_pair(freq[x], x));  //inserting if frequency is not zero

        //median
        if(high.find(x)!=high.end())
        {
            high.erase(high.find(x));
        }
        else{
            low.erase(low.find(x));
        }
        balance();
    }
    double mean(){
        return sum/count; 
    }

    double variance()
    {
        return (sumsq/count)-(mean()*mean());
    }
    double mode()
    {
        return freq_order.rbegin()->second;
    }

    double median(){
        if((low.size()+high.size())%2){
            return *low.rbegin();
        }
        else{
            return (*low.rbegin()+ *high.begin())/2.0;
        }
    }
    
};

void solve(){
    dashboard dbb;
    dbb.insert(1);
    dbb.insert(2);
    dbb.insert(2);
    dbb.insert(3);
cout<<dbb.mean()<<endl;    
cout<<dbb.variance()<<endl;
cout<<dbb.mode()<<endl;
cout<<dbb.median()<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}