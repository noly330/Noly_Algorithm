#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int a = 0; a < nums.size(); a++){
            // 如果当前数字大于0，后面的数字都大于0，不可能和为0
            if(nums[a] > 0) 
                break;
            
            // 跳过重复的第一个数
            if(a > 0 && nums[a] == nums[a-1])
                continue;

            int left = a + 1;
            int right = nums.size() - 1;

            while(left < right){
                int sum = nums[a] + nums[left] + nums[right];

                if(sum == 0){
                    ans.push_back({nums[a], nums[left], nums[right]});
                    
                    // 找到三元组后才跳过重复元素
                    while(left < right && nums[left] == nums[left + 1])
                        left++;
                    while(left < right && nums[right] == nums[right - 1])
                        right--;
                    
                    left++;
                    right--;
                }
                else if(sum < 0){
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return ans;
    }
};