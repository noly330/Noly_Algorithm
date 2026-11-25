#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        heapSort(nums,nums.size());

        return nums[k-1];
    }

    void heapify(vector<int>& nums,int p,int n){
        while(true){
            int l = 2*p + 1;
            int r = 2*p + 2;
            int minpos = p;
            if(l<n && nums[l]<nums[minpos]){
                minpos = l;
            }
            if(r<n && nums[r]<nums[minpos]){
                minpos = r;
            }
            if(minpos == p){
                break;
            }
            swap(nums[minpos],nums[p]);
            p = minpos;
        }
    }

    void heapSort(vector<int>& nums,int n){
        int start = (n-1)/2;
        for(int i = start;i>=0;i--){
            heapify(nums,i,n);
        }
        for(int i = n - 1;i>0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,0,i);
        }
    }
};