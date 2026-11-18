#include<bits/stdc++.h>
using namespace std;

//这个更直观一点，速度更快的去重方法在第一次写hot100的时候有
class Solution {
public:

    vector<vector<int>>  ans;
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();

        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-2;i++){
            if(nums[i]>0){
                break;
            }
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            int l = i+1;
            int r = n-1;

            while(l<r){
                if(l-1>i && nums[l] == nums[l-1]){
                    l++;
                    continue;
                }
                if(r+1<n && nums[r] == nums[r+1]){
                    r--;
                    continue;
                }
                if(nums[i]+nums[l]+nums[r] == 0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++,r--;
                    continue;
                }

                if(nums[i]+nums[l]+nums[r] < 0){
                    l++;
                    continue;
                }
                if(nums[i]+nums[l]+nums[r] > 0){
                    r--;
                    continue;
                }
            }
        }

        return ans;
    }
};