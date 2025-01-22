#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> queens;
                                                                                //complexity of code O(N!)
bool check(int row,int col){
    for(int prow=0; prow<row;prow++){
        int pcol=queens[prow];
        //need to place queen at (row,col) and check if it gets attacked from previous row (prow) and pcol position queen
        if(pcol==col||abs(row-prow)==abs(col-pcol)) { //attacking condition   //diagonal is of slope 1 or -1 and so it is |(Y2-Y1)/(X2-X1)|=1
            return 0;
        }
    }
    return 1;
}

int cnt=0;
void rec(int level){ //level is row
    //base case
    if(level==n){
        cnt++;
        //print queen
        for(int i=0;i<n;i++){
            cout<<queens[i]<<" ";
            
        } cout<<endl;

    }

    //recursive case
    for(int col=0; col<n; col++){       //loop over choice
        //check and place
        if(check(level,col)){
            //place/move
            queens.push_back(col);
            rec(level+1);
            queens.pop_back();
        }
    }
}

void solve()
{
    cin >> n;
    rec(0);
    cout<<cnt<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t; cin>>_t;while(_t--)
    solve();
}