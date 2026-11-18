#include<bits/stdc++.h>
using namespace std;

const int N =1e6;
class Solution {
public:

    vector<vector<int>> ans;
    vector<int> output;
    int n;
    bool vis[N];
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        dfs(0,nums);
        return ans;
        
    }



    void dfs(int len, vector<int> &num){
        if(len == n){
            ans.push_back(output);
            return;
        }

        for(int i =0;i<n;i++){
            if(vis[i] == true){
                continue;
            }

            vis[i] = true;
            output.push_back(num[i]);
            dfs(len+1,num);
            vis[i] = false;
            output.pop_back();
        }
    }
};