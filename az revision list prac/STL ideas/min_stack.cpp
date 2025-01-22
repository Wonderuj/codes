#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
public:
    MinStack()
    {
    }
    stack<int> st;
    multiset<int> s;
    int mini = 1e9;
    void push(int x)
    {
        st.push(x);
        s.insert(x);
        return;
    }

    void pop()
    {
        if (!st.empty() && s.find(st.top()) != s.end())
        {
            s.erase(s.find(st.top()));
        }

        if (!st.empty())
        {
            st.pop();
        }
        return;
    }

    int top()
    {
        if (!st.empty())
        {
            return st.top();
        }
        else
        {
            return -1;
        }
    }

    int getMin()
    {
        if (!st.empty())
        {
           return *s.begin();
        }
        else
        {
            return -1;
        }

    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    MinStack s;

    while (q--)
    {
        string op;
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (op == "pop")
        {
            s.pop();
        }
        else if (op == "top")
        {
            cout << s.top() << "\n";
        }
        else if (op == "getMin")
        {
            cout << s.getMin() << "\n";
        }
    }

    return 0;
}