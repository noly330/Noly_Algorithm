#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0 , r = n-1;
        int ans = (r-l)*min(height[l],height[r]);
        while(l<r){
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
            ans = max((r-l)*min(height[l],height[r]),ans);
        }
        return ans;
    }
};