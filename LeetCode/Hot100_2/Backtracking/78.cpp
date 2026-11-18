#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        dfs(nums.size(),0,nums,current);

        return ans;
    }

    void dfs(int n,int p,vector<int>& nums,vector<int> &current){
        if(p == n){
            ans.push_back(current);
            return;
        }

        //选与不选
        current.push_back(nums[p]);
        dfs(n,p+1,nums,current);
        current.pop_back();
        dfs(n,p+1,nums,current);
    }


};