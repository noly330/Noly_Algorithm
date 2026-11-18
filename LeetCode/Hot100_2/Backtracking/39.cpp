#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> mid;
        int n = candidates.size();
        dfs(ans,mid,candidates,n,target,0,0);
        return ans;
    }

    void dfs(vector<vector<int>> &ans,vector<int> & mid,vector<int>& nums,int n,int target,int sum,int p){
        if(sum>target)
            return;
        if(sum == target){
            ans.push_back(mid);
            return;
        }

        for(int i = p;i<n;i++){
            if(sum + nums[i] <= target){
                mid.push_back(nums[i]);
                dfs(ans,mid,nums,n,target,sum + nums[i],i);
                mid.pop_back();
            }
        }
    }
};