#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int mi = INT_MAX;
        int ans = 0;
        for(int i = 0;i < n; i++){
            ans = max(ans,prices[i] - mi);
            mi = min(mi,prices[i]);
        }
        return ans;
    }
};