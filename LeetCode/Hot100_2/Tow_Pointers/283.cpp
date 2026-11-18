#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int l,r;
        
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                l = i;
                r = l +1;
                break;
            }
        }

        // for(int i = l;i<n;i++){
        //     if(nums[i] != 0){
        //         r = i;
        //         break;
        //     }
        // }

        while(r<n){
            if(nums[l] == 0 && nums[r] != 0){
                swap(nums[l],nums[r]);
                
                for(int i = l;i<n;i++){
                    if(nums[i] == 0) {
                        l = i;
                        r = l+1;
                        break;;
                    }
                }
            }
            else{

                r++;
            }
        }
    }
};