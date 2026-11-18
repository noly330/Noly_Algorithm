#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //这个未出现的最小数，必须是[1,n]内的
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n+1,1);
        for(int i = 0;i<n;i++){
            if(nums[i]>0 && nums[i] <=n){
                a[nums[i]] = -1;
            }
        }

        for(int i = 1;i<=n;i++){
            if(a[i] == 1){
                return i;
            }
        }

        return n+1;
    }
};