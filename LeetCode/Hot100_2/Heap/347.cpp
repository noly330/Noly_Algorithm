#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            mp[nums[i]]++;
        }

        vector<pair<int,int>> a;
        for(auto x : mp){
            a.push_back({x.first,x.second});
        }

        QSort(a,0,a.size()-1);
        vector<int> ans;

        for(int i=0;i<k;i++){
            ans.push_back(a[i].first);
        }

        return ans;
    }

    int partition(vector<pair<int,int>> &a,int low,int hight){
        int l = low;
        int pivot = a[hight].second;
        for(int r = low;r<hight;r++){
            if(a[r].second > pivot){
                swap(a[l],a[r]);
                l++;
            }
        }
        swap(a[l],a[hight]);

        return l;
    }

    void QSort(vector<pair<int,int>> &a,int low,int hight){
        if(low<hight){

            int mid = partition(a,low,hight);
            QSort(a,low,mid-1);
            QSort(a,mid+1,hight);
        }
    }
};