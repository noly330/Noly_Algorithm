#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        if(n == 0){
            return {};
        }
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;
        for(int i = 0;i<n;i++){
            int l = intervals[i][0],r = intervals[i][1];

            if(ans.size() ==0 || ans.back()[1] < l){
                ans.push_back({l,r});
            }
            else{
                ans.back()[1] = max(ans.back()[1],r);
            }
        }

        return ans;
    }

    
};