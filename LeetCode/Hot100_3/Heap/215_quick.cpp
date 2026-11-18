#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        qSort(nums,0,nums.size()-1);

        return nums[k-1];
    }

    int partition(vector<int>& nums,int low,int height){
        int pivot = nums[height];
        int i = low;

        for(int j = low;j<height;j++){
            if(nums[j] > pivot){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[height]);
        return i;
        
    }

    void qSort(vector<int>& nums,int low,int height){

        if(low>height){
            return;
        }
        int mid = partition(nums,low,height);
        qSort(nums,low,mid-1);
        qSort(nums,mid+1,height);
    }
};