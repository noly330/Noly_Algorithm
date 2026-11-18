#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        heapSort(nums,nums.size());

        return nums[k-1];
    }

    void heapify(vector<int> &nums,int i,int n){
        
        while(true){
            int l = 2*i + 1;
            int r = 2*i + 2;
            int currentMinIndex = i;
            
            if(l<n && nums[currentMinIndex] > nums[l]){
                currentMinIndex = l;
            }
            if(r <n && nums[currentMinIndex] > nums[r]){
                currentMinIndex = r;
            }

            if(currentMinIndex == i){
                break;
            }

            swap(nums[i],nums[currentMinIndex]);
            i = currentMinIndex;
        }

    }

    void heapSort(vector<int> &nums,int n){
        int start = (n-1)/2;

        for(int i = start;i>=0;i--){
            heapify(nums,i,n);
        }

        for(int i = n-1;i>0;i--){
            swap(nums[i],nums[0]);
            heapify(nums,0,i);
        }
    }
};