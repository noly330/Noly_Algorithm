#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> mid;
        int n = nums.size();
        dfs(mid,nums,0,n);
        return ans;
    }

    void dfs(vector<int>& mid,vector<int>& nums,int p,int n){
        if(p == n){
            ans.push_back(mid);
            return;
        }
        mid.push_back(nums[p]);
        dfs(mid,nums,p+1,n);
        mid.pop_back();
        dfs(mid,nums,p+1,n);
    }
};