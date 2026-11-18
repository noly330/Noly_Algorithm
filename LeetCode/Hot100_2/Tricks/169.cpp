#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
struct noly
{
    int val;
    int count;
};

    int majorityElement(vector<int>& nums) {
        noly x = {nums[0],1};

        for(int i = 1;i<nums.size();i++){
            if(nums[i] == x.val){
                x.count++;
                
            }
            else{
                if(x.count == 0){
                    x.val = nums[i];
                    x.count = 1;
                }
                else{
                    x.count --;
                }
            }
        }

        return x.val;
    }
};