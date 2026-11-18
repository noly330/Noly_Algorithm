#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpMax(n,INT_MIN);
        vector<int> dpMin(n,INT_MAX);
        int ans = INT_MIN;

        dpMax[0] = nums[0];
        dpMin[0] = nums[0];

        ans=max(max(dpMax[0],dpMin[0]),ans);
        for(int i = 1;i<n;i++){
            dpMax[i] = max(max(dpMax[i-1]*nums[i],dpMin[i-1]*nums[i]),nums[i]);
            dpMin[i] = min(min(dpMax[i-1]*nums[i],dpMin[i-1]*nums[i]),nums[i]);

            ans=max(max(dpMax[i],dpMin[i]),ans);
        }

        return ans;
    }
};