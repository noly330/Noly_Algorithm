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

        qSort(arr,0,arr.size()-1);

         vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[i].index);
        }

        return ans;
    }

    int partition(vector<MyData> &arr,int low,int hight){
        int pivot = hight;

        int l = low,r = low;

        while(r<hight){
            if(arr[r].value > arr[pivot].value){
                swap(arr[l],arr[r]);
                l++;
            }

            r++;
        }

        swap(arr[l],arr[pivot]);

        return l;
    }

    void qSort(vector<MyData> &arr,int low,int hight){

        if(low >= hight)
            return;
        int mid = partition(arr,low,hight);

        qSort(arr,low,mid-1);
        qSort(arr,mid + 1,hight);
    }
};