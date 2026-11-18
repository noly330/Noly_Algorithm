#include <bits/stdc++.h>
using namespace std;


//没看懂
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();

        int end = 0;
        int maxPos = 0;
        int step = 0;

        for (int i = 0; i < n - 1; i++)
        {

            if (maxPos >= i)
            {
                maxPos = max(maxPos,1 + nums[i]);
                if(i == end){
                    end = maxPos;
                    step++;
                }
            }
        }

        return step;
    }
};