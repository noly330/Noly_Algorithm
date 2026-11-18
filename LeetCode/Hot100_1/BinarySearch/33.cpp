#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
        {
            return -1;
        }


        int l = -1;
        int r = n;

        while (l + 1 < r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            if (n == 1)
            {
                return nums[0] == target ? 0 : -1;
            }

            // 如果在左半区
            if (nums[0] <= nums[mid])
            {

                // 如果在左半区的0-mid内
                if (target >= nums[0] && target < nums[mid])
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }
            else
            {
                if (target <= nums[n - 1] && target > nums[mid])
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }
        }

        return -1;
    }
};