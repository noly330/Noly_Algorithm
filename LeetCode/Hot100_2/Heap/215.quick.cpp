#include <bits/stdc++.h>
using namespace std;
//TODO:这个快排超过时间限制了
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums,0,nums.size()-1);

        return nums[k-1];
    }

    void quickSort(vector<int>& nums,int l,int r){
        if(l>r)
            return;
        int mid = partition(nums,l,r);
        quickSort(nums,l,mid-1);
        quickSort(nums,mid+1,r);
    }

    int partition(vector<int>& nums,int low,int height){
        int i = low;
        int pivot = nums[height];

        for(int j = low;j < height;j++){
            if(nums[j] > pivot){
                swap(nums[i],nums[j]);
                i++;
            }
        }

        swap(nums[i],nums[height]);
        return i;

    }

    
};