/*QUESTION
You will be given a string, number, of digits from 2 to 9, output an array containing all the strings of lower case alphabets 
that could be made using the string of digits on an alphanumeric keypad, like the one shown in the picture.

https://docs.google.com/document/d/1m22-fMZ7ABm4TICJAUa05_spB0f1hS1I3LmQq4WGBj0/edit

Input Format

The first line contains a string S consisting of digits 2-9, |S| ≤ 12.

Output Format

Output the possible combination of words possible. Print the answer in lexicographical order.

Sample Input 1

23

Sample Output 1

ad
ae
af
bd
be
bf
cd
ce
cf*/

// #include<bits/stdc++.h>
// using namespace std;

// unordered_map<int, string>mp;


// void rec(string num, string output,int idx){
//     if(idx==(int)num.length()){
//         reverse(output.begin(),output.end());
//         cout<<output<<'\n';
//     }

//     int x= num[idx]-'0';
//     // cout<<x<<endl;
    
//     string temp=mp[x];
//     // cout<<temp<<endl;
//     for(int i=0;i<(int)temp.length();i++){
//         rec(num,temp[i]+output,idx+1);
//     }
    
// }

// void solve(){
//     string s;
//     cin>>s;
//     mp[2]="abc";
//     mp[3]="def";
//     mp[4]="ghi";
//     mp[5]="jkl";
//     mp[6]="mno";
//     mp[7]="pqrs";
//     mp[8]="tuv";
//     mp[9]="wxyz";
//     string output = "";
//     rec(s,output,0);
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     //int _t; cin>>_t;while(_t--)
//     solve();
// }


//------------------------------------------------------editorial solution-----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
string key[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string res;
string s;
vector<string> answer;
void rec(int i)
{
    if (i == s.length())
    {
        answer.push_back(res);
        return;
    }
    for (auto v : key[s[i] - '0'])
    {
        res.push_back(v);
        rec(i + 1);
        res.pop_back();
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    rec(0);
    for (auto v : answer)
        cout << v << endl;
}