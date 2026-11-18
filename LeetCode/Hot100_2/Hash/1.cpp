#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0;i < n;i++){
            if(mp.count(target - nums[i])){
                ans.push_back(mp[target - nums[i]]);
                ans.push_back(i);

                return ans;
            }

            if(!mp.count(nums[i])){
                mp[nums[i]] = i;
            }
        }

        return ans;
    }
};