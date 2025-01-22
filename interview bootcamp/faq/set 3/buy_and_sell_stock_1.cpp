#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int BuyAndSellStock(vector<int> &a) 
{
    int n= a.size();
    int ans=0;
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        mini=min(mini, a[i]);
        ans=max(ans, a[i]-mini);
    }
    return ans;
}


int main(){
   IOS
   
   int t;
   cin>>t;
   
   while(t--){
       int n;
       cin>>n;
       
       vector<int> a(n);

       for (int i = 0; i < n; ++i) {
           cin>>a[i];
       }
       
       cout << BuyAndSellStock(a) << "\n";
   }

   return 0;
}