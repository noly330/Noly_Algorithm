#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> output;
    vector<vector<int>> ans;
    int n;
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();

        dfs(nums,0);

        return ans;
    }


    void dfs(vector<int> &nums,int p){
        if(p == n){
            ans.push_back(output);
            return;
        }

        dfs(nums,p+1); //不选
        output.push_back(nums[p]);
        dfs(nums,p+1);
        output.pop_back();

    }
};