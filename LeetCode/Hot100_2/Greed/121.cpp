#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int minprices = prices[0];
        int ans = 0;
        for(int i = 1; i < n; i++){
            ans = max(ans,prices[i] - minprices);

            if(minprices>prices[i]){
                minprices = prices[i];
            }
        }

        return ans;
    }
};