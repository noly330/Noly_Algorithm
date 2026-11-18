#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct MyData
    {
        int index;
        int value;
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (mp.count(nums[i]))
            {
                mp[nums[i]]++;
            }
            else
            {
                mp[nums[i]] = 1;
            }
        }

        vector<MyData> arr;
        for (auto x : mp)
        {
            arr.push_back({x.first, x.second});
        }

        heapSort(arr,arr.size());

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[i].index);
        }

        return ans;
    }

    void heapify(vector<MyData> &arr,int p,int n){
        int left = 2*p+1;
        int right = 2*p+2;

        int currentMin = p;
        if(left<n && arr[left].value < arr[currentMin].value){
            currentMin = left;
        }

        if(right<n && arr[right].value < arr[currentMin].value){
            currentMin = right;
        }

        if(currentMin != p){
            swap(arr[p],arr[currentMin]);
            heapify(arr,currentMin,n);
        }
    }

    void heapSort(vector<MyData> &arr,int n){
        int p = (n-1)/2;

        for(int i = p;i>=0;i--){
            heapify(arr,i,n);
        }

        for(int i = n - 1;i>0;i--){
            swap(arr[i],arr[0]);
            heapify(arr,0,i);
        }
    }
};