#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int dp[n];
        int ans = INT_MIN;

        dp[0] = nums[0];
        ans = nums[0];
        for(int i = 1;i<n;i++){
            dp[i] = max(nums[i],dp[i-1] + nums[i]);
            ans = max(ans,dp[i]);
        }

        return ans;
    }
};