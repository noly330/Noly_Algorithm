#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans = 0;
        int currnetMin = 10000;
        int n = prices.size();

        for(int i =0;i<n;i++){
            ans = max(ans,prices[i] - currnetMin);
            if(prices[i] < currnetMin){
                currnetMin = prices[i];
            }

        }

        return ans;
    }
};