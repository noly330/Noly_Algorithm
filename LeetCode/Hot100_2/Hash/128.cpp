#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        if(n == 0)
            return 0;
        int ans = 1;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){

            //第一次遇到这个数字
            if(!mp.count(nums[i])){

                //找找前一个有没有
                if(mp.count(nums[i]-1)){
                    mp[nums[i]] = mp[nums[i]-1] + 1;
                    ans  = max(ans,mp[nums[i]]);
                }
                else{
                    mp[nums[i]] = 1;
                }
            }
        }

        return ans;
    }
};