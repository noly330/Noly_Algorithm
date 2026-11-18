#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);

        vector<int> lsum(n,1);
        vector<int> rsum(n,1);

        lsum[0] = 1;
        for(int i = 1;i<n;i++){
            lsum[i] = lsum[i-1] * nums[i-1];
        }

        rsum[n-1] = 1;
        for(int i = n-2;i>=0;i--){
            rsum[i] = rsum[i+1]*nums[i+1];
        }

        for(int i =0;i<n;i++){
            ans[i] = lsum[i] * rsum[i];
        }

        return ans;
    }
};