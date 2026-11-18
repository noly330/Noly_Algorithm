#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int l = 0,r = n-1;

        int lsum = 1;
        int rsum = 1;
        while(l<n&&r>=0){
            ans[l] *= lsum;
            ans[r] *= rsum;
            lsum *= nums[l];
            rsum *= nums[r];
            l++,r--;

        }
        return ans;
    }
};