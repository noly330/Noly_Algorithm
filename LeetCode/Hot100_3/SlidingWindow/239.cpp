#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        vector<int> ans;
        for(int i=0;i<k;i++){
            q.push({nums[i],i});
        }
        ans.push_back(q.top().first);
        for(int i = 1;i<nums.size()-k +1;i++){
            int p = i+k-1;
            q.push({nums[p],p});

            while(q.size()){
                if(q.top().second >=i){
                    ans.push_back(q.top().first);
                    break;
                }
                else{
                    q.pop();
                }
            }
        }
        return ans;

    }
};