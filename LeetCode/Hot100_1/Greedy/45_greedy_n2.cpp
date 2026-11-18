#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int position = n - 1;
        int step = 0;
        while(position > 0){

            for(int i =0;i< position;i++){
                if(i+nums[i] >= position){
                    step ++;
                    position = i;
                    break;

                }
            }
        }

        return step;
        
    }
};