#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    stack<char>st;
    int count =0;
    for (int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else{
                count=count +1;
            }
        }
        }
    if(!st.empty()){
        count=count+st.size();
    }
    cout<<count<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t;while(_t--)
    solve();
}

/* another solution---------------------------------------------------------------------------------
#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
#define ii pair<int,int>
#define endl "\n"
#define f first
#define s second 
long double PI=acos(-1.0);
using namespace std;
void solve()
{
	string s;cin>>s;
	int n=s.length();
	int ans=0,depth=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
		{
			depth++;
		}
		else
		{
			depth--;
		}
		if(depth<0)
		{
			ans+=1;
			depth=0;
		}
	}
	cout<<ans+depth<<endl;
}	
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int _T;cin>> _T;while(_T --)
	solve();
}
*/
