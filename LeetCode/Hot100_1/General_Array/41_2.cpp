#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int &num : nums){
            if(num <=0){
                num = n+1;
            }
        }

        for(int num : nums){
            num = abs(num);
            if(num <= n){
                nums[num-1] = -abs(nums[num-1]);  //标记nums[i-1]存在
            }
        }

        for(int i =0;i<n;i++){
            if(nums[i] > 0){  //大于0就是没被标记
                return i+1;
            }
        }

        return n+1;
    }
};