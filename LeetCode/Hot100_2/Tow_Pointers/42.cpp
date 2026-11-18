#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lMax(n);
        vector<int> rMax(n);

        lMax[0] = height[0];
        rMax[n-1] = height[n-1];

        for(int i = 1;i<n-1;i++){
            if(height[i] > lMax[i-1]){
                lMax[i] = height[i];
            }
            else{
                lMax[i] = lMax[i-1];
            }
        }

        for(int i = n-2;i>0;i--){
            if(height[i] > rMax[i+1]){
                rMax[i] = height[i];
            }
            else{
                rMax[i] = rMax[i+1];
            }
        }

        int ans = 0;

        for(int i =1;i<n-1;i++){
            int temp = min(lMax[i],rMax[i]);
            ans += temp - height[i];
        }

        return ans;
    }
};