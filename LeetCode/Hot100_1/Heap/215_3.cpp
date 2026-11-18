#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        qSort(nums,0,nums.size()-1);

        return nums[k-1];
    }


    void qSort(vector<int> &nums,int low,int hight){

        if(low >= hight)
            return;
        int mid = partition(nums,low,hight);
        qSort(nums,low,mid - 1);
        qSort(nums,mid+1,hight);
    }

    int partition(vector<int> &nums,int low,int hight){
        int i = low;
        int pivot = nums[hight];

        for(int j =low;j<hight;j++){
            if(nums[j] > pivot){
                swap(nums[i],nums[j]);
                i++;
            }
        }

        swap(nums[i],nums[hight]);
        return i;
    }


};