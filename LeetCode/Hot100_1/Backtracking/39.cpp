#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> mid;
        dfs(candidates,mid,0,target,0);
        
        return ans;
    }

    
    void dfs(vector<int> &condidates,vector<int> &mid,int sum,int target,int p){
        if(p >= condidates.size())
            return;
        if(sum>target)  
            return;
        if(sum==target){
            ans.push_back(mid);
            return;
        }

        //不选
        dfs(condidates,mid,sum,target,p+1);
        
        sum += condidates[p];
        mid.push_back(condidates[p]);
        dfs(condidates,mid,sum,target,p);
        mid.pop_back();
    }
};