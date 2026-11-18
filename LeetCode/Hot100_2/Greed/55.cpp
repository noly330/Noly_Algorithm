#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxdis = 0;

        for(int i = 0;i<nums.size();i++){
            if(i<=maxdis){
                maxdis = max(maxdis,i+nums[i]);
            }
            else{
                break;
            }
        }

        return maxdis>=nums.size()-1;
    }
};