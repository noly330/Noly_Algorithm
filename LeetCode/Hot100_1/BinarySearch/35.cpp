#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n =nums.size();
        int l =0;int r = n;

        if(n == 1){
            if(nums[0] == target){
                return 0;
            }

            if(nums[0] < target){
                return 1;
            }
            if(nums[0] >target){
                return 0;
            }
        }

        while(l<r){
            int mid = l + (r-l)/2;

            if(nums[mid] > target){
                r = mid -1;
            }
            else if(nums[mid] < target){
                l = mid +1;
            }
            else{
                return mid;
            }
        }

        return l;
    }
};