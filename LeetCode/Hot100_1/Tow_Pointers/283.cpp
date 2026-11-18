#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int l = -1;
        int r = -1;

        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                l = r = i;
                break;
            }
        }

        if(l == -1){

        }
        else{
            while(r < n){
                if(nums[r] != 0 && nums[l] == 0){
                    nums[l] = nums[r];
                    l++;
                    nums[r] = 0;
                }
                r++;
            }
        }

    }
};