#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:

    stack<int> st;
    stack<int> min_st;
    MinStack() {
        min_st.push(INT_MAX);
    }
    
    void push(int value) {
        st.push(value);
        min_st.push(min(min_st.top(),value));
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
