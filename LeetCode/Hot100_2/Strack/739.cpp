#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> stk;
        for(int i = 0;i<n;i++){
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){
                int index = stk.top();
                ans[index] = i - index;
                stk.pop();

            }
            stk.push(i);
        }

        return ans;
    }
};

