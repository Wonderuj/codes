#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
public:
    stack<int> s;
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    MinStack()
    {
    }

    void push(int x)
    {
        s.push(x);
        if (x < min1)
        {
            min2 = min1;
            min1 = x;
        }
    }

    void pop()
    {
        if (!s.empty() && s.top() != min1)
            s.pop();
        else if (!s.empty() && s.top() == min1)
        {
            min1 = min2;
            s.pop();
        }
    }

    int top()
    {
        if (!s.empty())
        {
            return s.top();
        }
        else
        {
            return -1;
        }
    }

    int getMin()
    {
        if (!s.empty())
        {
            return min1;
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