#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int st[7];
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> mid;
        n = nums.size();
        dfs(0,mid,nums);
        return ans;
    }

    void dfs(int p,vector<int>& mid,vector<int>& nums){
        if(p >= n){
            ans.push_back(mid);
            return;
        }

        for(int i = 0;i<n;i++){
            if(st[i] == 1)
                continue;
            mid.push_back(nums[i]);
            st[i] = 1;
            dfs(p+1,mid,nums);
            mid.pop_back();
            st[i] = 0;
        }
    }
};