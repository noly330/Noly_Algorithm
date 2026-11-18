#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxp = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(i>maxp)
                return false;
            maxp = max(maxp,i+nums[i]);

        }

        return true;
    }
};