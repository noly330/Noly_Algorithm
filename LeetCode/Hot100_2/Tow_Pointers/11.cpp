#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0;
        int r = n-1;
        while(l<r){
            int current = (r-l)*min(height[l],height[r]);
            ans = max(ans,current);

            if(height[l] <= height[r]){
                l++;
            }else{
                r--;
            }
        }

        return ans;
    }
};