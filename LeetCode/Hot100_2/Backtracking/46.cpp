#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int visited[n];
        memset(visited,0,sizeof(visited));
        vector<int> mid;
        dfs(nums,mid,visited,0,n);

        return ans;
    }

    void dfs(vector<int>& nums,vector<int>& mid,int *visited,int p,int n){
        if(p == n){
            ans.push_back(mid);
            return;
        }

        for(int i = 0;i<n;i++){
            if(visited[i] == 0){
                mid.push_back(nums[i]);
                visited[i] = 1;
                dfs(nums,mid,visited,p+1,n);
                mid.pop_back();
                visited[i] = 0;
            }
        }
    }
};