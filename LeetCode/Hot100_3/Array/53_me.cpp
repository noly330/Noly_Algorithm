#include<bits/stdc++.h>
using namespace std;

//之前写过动态规划解法，
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans =  nums[0];
        int cur = 0;
        for(int i = 0;i<n;i++){
            cur += nums[i];
            ans = max(ans,cur);
            if(cur<0){
                cur = 0;
            }
        }
        return ans;
    }
};