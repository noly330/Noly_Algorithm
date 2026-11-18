#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<int> x_stk;
    stack<int> min_stk;
    MinStack()
    {
        min_stk.push(INT_MAX);
    }

    void push(int value)
    {
        x_stk.push(value);
        min_stk.push(min(min_stk.top(), value));
    }

    void pop()
    {
        x_stk.pop();
        min_stk.pop();
    }

    int top()
    {
        return x_stk.top();
    }

    int getMin()
    {
        return min_stk.top();
    }
};