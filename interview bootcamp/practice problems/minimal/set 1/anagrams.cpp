#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s,t;
    getline(cin, s);
    getline(cin,t);
    int sum=0;
    if (s.length() != t.length())
    {
        cout<<"N\n";
        return;
    }
    
    vector<int>v(26,0);
    for(int i=0;i<(int)s.length();i++){
       v[s[i]-'a']++;
       v[t[i]-'a']--;
    }

    for(int i=0;i<26;i++){
        if(v[i]!=0){
            cout << "N\n";
            return;
        }
    }
    
    cout<<"Y\n";
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    // dummy getline
    string temp;
    getline(cin, temp);
    while (_t--)
        solve();
}