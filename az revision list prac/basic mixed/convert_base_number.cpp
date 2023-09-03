#include<bits/stdc++.h>
using namespace std;


void solve(){
    long long n,a,b,x, prod, cnt=0;
    string s, str;
    char ch;
    cin>>s>>a>>b;
    n=s.length();
    prod=1;

    //A0[Sn-1]+A1[Sn-2]+A3[Sn-3]+-----------------+An-1[S0] to convert base A to base 10

    for(int i=n-1; i>=0;i--){
        if(s[i]>='A' && s[i]<='Z'){
            x=10+(s[i]-'A');
        }
        else{
            x=s[i]-'0';
        }

        cnt+=x*prod;

        prod=prod*a;                 //incrementing power of A for next interation so as to be multiplied to x
    }

    prod=cnt;   //base 10 number is stored in prod now

    while(prod!=0){
        int remainder= prod%b;
        if(remainder>=10 && remainder<=35){
            ch='A'+(remainder-10);
        }
        else{
            ch='0'+remainder;
        }
        str+=ch;
        prod=prod/b;
    }
    reverse(str.begin(), str.end());
    cout<<str<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}
