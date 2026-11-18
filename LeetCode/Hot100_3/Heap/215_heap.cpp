#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        heapSort(nums);

        return nums[k-1];
    }

    void heapity(vector<int>& nums,int i,int n){
        
        while(true){
            int left = 2*i + 1;
            int right = 2*i +2;
            int currentMin = i;
            if(left<n && nums[left] < nums[currentMin]){
                currentMin = left;
            }
            if(right<n && nums[right] < nums[currentMin]){
                currentMin = right;
            }
            if(currentMin == i){
                break;
            }
            swap(nums[i],nums[currentMin]);
            i = currentMin;
        }
    }

    void heapSort(vector<int>& nums){
        int n = nums.size();
        for(int i = (n-1)/2;i>=0;i--){
            heapity(nums,i,n);
        }

        for(int i = n-1;i>0;i--){
            swap(nums[i],nums[0]);
            heapity(nums,0,i);
        }
    }
};