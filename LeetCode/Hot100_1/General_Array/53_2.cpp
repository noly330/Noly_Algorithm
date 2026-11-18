#include <bits/stdc++.h>
using namespace std;


//前缀和
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        int low = 0;
        int sum = 0;

        for(int i : nums){
            sum += i;
            ans = max(sum-low,ans);
            low = min(sum,low);
        }

        return ans;
    }
};