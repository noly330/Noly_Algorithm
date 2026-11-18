#include<bits/stdc++.h>
using namespace std;

//自己的方法
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int start = -1;
        for(int i =0;i<n;i++){
            if(nums[i] >0){
                start = i;
                break;
            }
        }

        if(start == -1){
            return 1;
        }

        int p = 1;
        int ans = 1;
        while(start < n){
            if(start>0&&nums[start] == nums[start-1]){
                start++;
                continue;
            }

            if(nums[start] != p){
                ans = p;
                break;
            }
            start++;
            p++;
            ans = p;
        }

        return ans;
    }
};