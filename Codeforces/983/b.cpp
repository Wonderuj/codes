
// #include <iostream>
// using namespace std;

// int main()
// {
//     int a,b,n;
//     cin>>a>>b>>n;
    
//     cout<<min((n-a)/b +1 , (n-b)/a +1)<<endl;
// }


#include <bits/stdc++.h>
using namespace std;

int func(vector<int>& nums,int n)
{
    int count = 0;
    map<int,int> fq;
    fq[0] = 1;
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += nums[i];
        if(fq.count(sum))
        {
            count += 1;
        }
        fq[sum]++;
    }
    
    return count;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &x:v) cin>>x;
    
    cout<<func(v,n);
}

