#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int pos = n-1;

        int ans = 0;
        while(pos > 0){
            for(int i = 0;i<n;i++){
                if(i+nums[i]>=pos){
                    ans++;
                    pos = i;
                    break;
                }
            }
        }

        return ans;
    }
};