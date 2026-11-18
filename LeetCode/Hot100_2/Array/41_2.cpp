#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //这个未出现的最小数，必须是[1,n]内的
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        //排除负数
        for(int i = 0;i<n;i++){
            if(nums[i]<=0)
                nums[i] = n+1;
        }

        for(int i = 0;i<n;i++){
            int num = abs(nums[i]);
            if(num <= n ){
                nums[num - 1] = -abs(nums[num-1]);
            }
        }

        for(int i = 0;i<=n;i++){
            if(nums[i] > 0){
                return i +1;
            }
        }
        
        return n+1;
    }
};