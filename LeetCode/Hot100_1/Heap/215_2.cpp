#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        heapSort(nums, nums.size());

        return nums[k - 1];
    }

    void heapify(vector<int> &nums, int i, int n)
    {
        while(true){
            int l = 2*i+1;
            int r = 2*i+2;
            int currentMin = i;
            if(l<n && nums[currentMin] > nums[l]){
                currentMin = l;
            }

            if(r<n && nums[currentMin] > nums[r]){
                currentMin = r;
            }

            if(currentMin == i)
                break;
            
            swap(nums[i],nums[currentMin]);
            i = currentMin;
        }
    }

    void heapSort(vector<int> &nums, int n)
    {
        //建堆
        for(int i = (n-1)/2;i>=0;i--){
            heapify(nums,i,n);
        }

        for(int i =n-1;i>0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,0,i);
        }
    }
};