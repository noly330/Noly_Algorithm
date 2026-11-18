#include<bits/stdc++.h>
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
            if(height[i] < lMax[i-1]){
                lMax[i] = lMax[i-1];
            }
            else{
                lMax[i] = height[i];
            }
        }

        for(int j = n-2;j>0;j--){
            if(height[j] < rMax[j+1]){
                rMax[j] = rMax[j+1];
            }
            else{
                rMax[j] = height[j];
            }
        }
        int ans = 0;

        //左右两边装不了水，可以放弃
        //如果非要计算左右两边的格子，那上面的for循环，从左遍历要包含最右边的格子
        //同理从右向左遍历也是如此
        //否则：比如lMax[n-1] = 0,rMax[n-1] = height[n-1]，到最后计算的时候，会取0这个数字减去height[n-1]
        for(int i=1;i<n - 1;i++){
            ans+=min(lMax[i],rMax[i]) - height[i];
        }

        return ans;
    }
};