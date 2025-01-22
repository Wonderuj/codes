//g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
//Fast IO: Use scanf and printf
#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define len(x) (int)x.length()
#define ac(x, i) get<i>(x)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll ,ll>
#define pli pair<ll, int>
#define ff first
#define ss second
#define trace(x)    cerr << #x << ": " << x << "\n"
#define trav0(a, n) cerr << #a << "[" << n <<  "] = ["; for (int i = 0; i < n; i++) cerr << a[i] << ", "; cerr << "]\n"
#define trav1(a, n) cerr << #a << "[" << n <<  "] = ["; for (int i = 1; i <= n; i++) cerr << a[i] << ", "; cerr << "]\n"
#define trap0(a, n) cerr << #a << "[" << n <<  "] = ["; for (int i = 0; i < n; i++) cerr << "(" << a[i].ff << ", " << a[i].ss << "), "; cerr << "]\n"
#define trap1(a, n) cerr << #a << "[" << n <<  "] = ["; for (int i = 1; i <= n; i++) cerr << "(" << a[i].ff << ", " << a[i].ss << "), "; cerr << "]\n"
#define travMap(a)  cerr << #a << "[" << sz(a) <<  "] = ["; for (auto i : a) cerr << "(" << i.ff << ", " << i.ss << "), "; cerr << "]\n"
#define traverse(a) cerr << #a << "[" << sz(a) <<  "] = ["; for (auto i : a) cerr << i << ", "; cerr << "]\n"
#define random_permute(x) shuffle(all(x), mt)
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a)) 
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a)) 
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a)) 
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a)) 
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a)) 
#define FOREACH(a, b) for (auto&(a) : (b)) 
#define REP(i, n) FOR(i, 0, n) 
#define REPN(i, n) FORN(i, 1, n) 




/* IMPORTANT ONES FREQUENTLY USED */
#define all(x) (x).begin(), (x).end()
#define B begin()
#define E end()
#define lb lower_bound
#define ub upper_bound






typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef vector<string> vs;
const int infi = 1e9;
const ll infl = 1e18;
const int MOD = 1e9 + 7;
//template <typename Map> bool map_compare (Map const &lhs, Map const &rhs) { return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());}
//auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
//mt19937 mt(seed);
//int randint(int p = MOD) { return mt() % p;}
//ll randlong(ll p = infl) { return mt() % p;}
ll log_2 (ll n) { return (n > 1ll)? 1ll + log_2(n/2): 0ll;}
inline void add(ll&a, ll b) {a += b; if (a >= MOD) a -= MOD;}
inline void sub(ll&a, ll b) {a -= b; if (a < 0) a += MOD;}

/* CONVERT A INTEGER TO A STRING */

inline string IntToString(ll a) 
{ 
    char x[100]; 
    sprintf(x, "%lld", a); 
    string s = x; 
    return s; 
} 


/* CONVERT A STRING TO AN INTEGER */
  
inline ll StringToInt(string a) 
{ 
    char x[100]; 
    ll res; 
    strcpy(x, a.c_str()); 
    sscanf(x, "%lld", &res); 
    return res; 
} 


/* TO ENTER A STRING AS A CHARACTER ARRAY AND THEN CONVERT IT TO A SINGLE STRING */

  
inline string GetString(void) 
{ 
    char x[1000005]; 
    scanf("%s", x); 
    string s = x; 
    return s; 
} 

/* CONVERT A STRING TO UPPER CASE */

  
inline string uppercase(string s) 
{ 
    int n = sz(s); 
    REP(i, n) 
    if (s[i] >= 'a' && s[i] <= 'z') 
        s[i] = s[i] - 'a' + 'A'; 
    return s; 
} 
  
/* CONVERT A STRING TO LOWER CASE */
  
inline string lowercase(string s) 
{ 
    int n = sz(s); 
    REP(i, n) 
    if (s[i] >= 'A' && s[i] <= 'Z') 
        s[i] = s[i] - 'A' + 'a'; 
    return s; 
} 

  
inline void OPEN(string s) 
{ 
#ifndef TESTING 
    freopen((s + ".in").c_str(), "r", stdin); 
    freopen((s + ".out").c_str(), "w", stdout); 
#endif 
} 

/* TO DISPLAY AN ARRAY ON THE SCREEN */

void showarr(ll arr[],ll n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
  }  

/*TO DISPLAY A VECTOR OF INTERGERS */


void showvec(vector <ll> v)
{
    int i;
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
  }  
  
/* TO CHECK IF A STRING IS PALINDROME*/  
  
  int isPalindrome(string str) 
{ 
    int l = 0; 
    int h = str.length() - 1; 
  while (h > l) 
    { 
        if (str[l++] != str[h--] ) 
        { 
            return 0; 
        } 
    } 
    return 1;
} 

/*   DISPLAY A VECTOR OF PAIRS */

  void showvecpair(vll v)
  {
    for(int i=0;i<sz(v);i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
      }
  }
 
/*   TO SORT A VECTOR OF PAIRS VIA SECOND ELEMENT.........CHECK NOTEPAD */  
  
bool sortbysec(const pll &a, 
              const pll &b) 
{ 
    return (a.second < b.second); 
}   

/*   TO PRINT BINARY REPRESENTATION OF ANY NUMBER */  

void bin(unsigned n) 
{ 
    unsigned i; 
    for (i = 1 << 31; i > 0; i = i / 2) 
        (n & i)? printf("1"): printf("0"); 
}     

/*   TO COUNT NUMBER OF SET BITS IN BINARY REPRESENTATION OF ANY NUMBER */  

ll cntset(ll n)
{
    bitset<64> b1(n);  //represents in 64 bit format
    return b1.count();
}  
  


// end of Sektor_jr template v2.0.3 (BETA) 
  
#define N 100005
 
long long int p[N];
 
void seive()
{
    ll i,j;
    for(i=0;i<N;i++)
        p[i]=i;
    for(i=2;i<=sqrt(N);i++)
    {
        if(p[i]!=i)
            continue;
        for(j=i*i;j<N;j+=i)
        {
            if(p[j]==j)
                p[j]=i;
        }
    }
    return;
}
ll power(ll n,ll x)    // To calculate n^x in O(logn) time
{
    ll j=n,prod=1;
    while(x)
    {
        if(x%2)
        {
            prod=((prod%MOD)*(j%MOD))%MOD;
        }
        j=(j*j)%MOD;
        x=x/2;
    }
    return prod;
}
  
ll fact(ll n)  
{
    ll i,prod=1;
    for(i=1;i<=n;i++)
    {
        prod=(prod*i)%MOD;
    }
    return prod;
}

 /*
    
    Topic:-  Reversing elements from index 5 to index 7
                reverse(vec1.begin() + 5, vec1.begin() + 8);
                Initial Vector:
                10 11 12 13 14 15 16 17 
                Reverse only from index 5 to 7 in vector:
                10 11 12 13 14 17 16 15 
    
    Topic:-  setting precision of 12
                cout <<setprecision(12)<<ans<<endl;

    Topic:-  setting precision of 2 digits after decimal place
               cout<<setprecision(2)<<fixed<<x<<" "<<endl;

    Topic :- Concatenate a number to the end of the string
            s+=to_string(x);

    Topic :- for accessing a pair of elements in c++ sets

    for(auto it=s1.B;it!=s1.E;it++)
    {
        a=it->first;
        b=it->first;            //Remember here only ' -> ' this symbol works and not the '.' operator

    }

    Topic :- Concatenate a number to the end of the string
                s+=to_string(x);

    Topic :- Converting a string to integer
               int x=stoi("4544");
               x=4544

    Topic :- Removing element from end of the vector :
    V.pop_back(); // equivalent to size--; O(1)

*/


// struct Test
// {
//     ll x,y,z;
// };


void solve()
{
    long long int a,b,c,d,x,y,n,m,k,l,i,j,Max=INT_MIN,Min=INT_MAX,ctr=0,cnt=0,ans=0;
    char ch;
    cin>>n;
    vector <pair<ll,ll> >v;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        v.pb({a,2});
        v.pb({b,1});
    }
    sort(all(v));
    cnt=0;
    Max=1;
    for(i=0;i<2*n;i++)
    {
        if(v[i].ss==2)
            cnt++;
        else
            cnt--;
        if(cnt>Max)
            Max=cnt;
    }
    cout<<Max<<endl;

}


int main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //#endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,T;
   
    T=1;
    cin>>T;
    
    for(i=1;i<=T;i++)
    {
        solve();
        //cout<<endl;
    }
    return 0;
    
    
}