#include <bits/stdc++.h>
using namespace std;


//思路：设前j个节点的最大值为dp[j]，这时候判断dp[i]是否大于dp[j]，如果大于，那么
//那么就可以让dp[i] = dp[j] + 1;，不过还是需要判断是否为最大值
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        
        for(int i =0;i<n;i++){
            dp[i] = 1;
            for(int j = 0;j<=i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }

        int ans = 0;
        for(int i =0;i<n;i++){
            ans = max(ans,dp[i]);
        }

        return ans;
    }
};