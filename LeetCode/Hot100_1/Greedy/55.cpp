#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxdis = 0;
        for(int i=0;i<n - 1;i++){
            if(i>maxdis)
                break;
            int dis = i + nums[i];
            maxdis = max(dis,maxdis);
        }
        cout<<maxdis<<endl;
        return maxdis >= n -1 ? true : false;
    }
};