#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            auto a = mp.find(target - nums[i]);
            if(a != mp.end()){
                return {a->second,i};
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return {};
    }
};