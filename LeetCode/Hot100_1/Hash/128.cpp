#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0;i<nums.size();i++){
            st.insert(nums[i]);
        }

        int ans = 0;
        for(auto i : st){
            int num = i;
            int res = 1;
            if(st.count(num-1))
                continue;
            while(st.count(num + 1)){
                res++;
                num++;
            }
            ans = max(ans,res);
        }

        return ans;
    }

};