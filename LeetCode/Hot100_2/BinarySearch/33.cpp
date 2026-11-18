#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = -1;
        int r = n;

        while(l+1<r){
            int mid = l+(r-l)/2;

            if(nums[mid] == target){
                return mid;
            }

            //如果左边有序
            if(nums[0] <= nums[mid]){
                if(nums[0] <= target && target < nums[mid]){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[n-1]){
                    l = mid;
                }
                else{
                    r = mid;
                }
            }

        }

        return -1;
    }
};