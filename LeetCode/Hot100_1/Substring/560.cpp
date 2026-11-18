#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;

        mp[0] = 1;
        int d = 0;
        int ans=0;
        for(int i=0;i<n;i++){
            d+=nums[i];
            if(mp.find(d - k) != mp.end()){
                ans+=mp[d-k];
            }

            mp[d]++;
        }

        return ans;
    }
};