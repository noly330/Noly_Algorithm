#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;

        int l = GetL(nums, target);
        int r = GetR(nums, target);
        // ans.push_back(l);
        // ans.push_back(r);

        ans.push_back(GetL(nums, target));
        ans.push_back(GetR(nums, target));

        return ans;
    }

    int GetL(vector<int> &nums, int target)
    {
        int l = -1, r = nums.size();

        while (l + 1 != r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }

        if(r>=nums.size()){
            return -1;
        }

        if (nums[r] == target)
            return r;
        else
            return -1;
    }

    int GetR(vector<int> &nums, int target)
    {
        int l = -1, r = nums.size();

        while (l + 1 != r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        if(l<0){
            return -1;
        }
        if (nums[l] == target)
            return l;
        else
            return -1;
    }
};