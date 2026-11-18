#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            if(sum == k){
                ans++;
            }

            if(mp.count(sum - k)){
                ans += mp[sum - k];
            }

            mp[sum]++;

        }

        return ans;
    }
};