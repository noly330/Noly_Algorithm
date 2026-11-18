#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(GetL(nums,target));
        ans.push_back(GetR(nums,target));

        return ans;
    }

    int GetL(vector<int>& nums,int target){
        int n = nums.size();
        int l = -1,r = n;
        while(l+1<r){
            int mid = l+(r-l)/2;
            if(nums[mid] < target){
                l = mid;
            }
            else{
                r = mid;
            }
        }

        if(r<n&&nums[r] == target)
            return r;
        else
            return -1;
        
    }

    int GetR(vector<int>& nums,int target){
        int n = nums.size();
        int l = -1,r = n;
        while(l+1<r){
            int mid = l+(r-l)/2;
            if(nums[mid] <= target){
                l = mid;
            }
            else{
                r = mid;
            }
        }

        if(l>-1 && nums[l] == target)
            return l;
        else
            return -1;
    }
};