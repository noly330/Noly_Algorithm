#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int dpMAX[n];
        int dpMIN[n];

        for (int i = 0; i < n; i++)
        {
            dpMAX[i] = -INT_MAX;
            dpMIN[i] = INT_MAX;
        }

        dpMAX[0] = nums[0];
        dpMIN[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++)
        {
            dpMAX[i] = max(max(dpMAX[i - 1] * nums[i], dpMIN[i - 1] * nums[i]), nums[i]);
            dpMIN[i] = min(min(dpMAX[i - 1] * nums[i], dpMIN[i - 1] * nums[i]), nums[i]);

            ans = max(dpMAX[i],ans);
        }

        return ans;
    }
};