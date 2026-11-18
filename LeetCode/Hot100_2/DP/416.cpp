#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            sum += nums[i];
        }
        if(sum % 2 != 0)
            return false;

        vector<bool> dp(sum,false);
        dp[0] = true;

        for(int i = 0;i<n;i++){
            for(int j = sum/2;j>=0;j--){
                if(j-nums[i]>=0){
                    if(dp[j] != true){
                        dp[j] = dp[j-nums[i]];
                    }
                }
            }
        }

        return dp[sum/2];
        
    }
};