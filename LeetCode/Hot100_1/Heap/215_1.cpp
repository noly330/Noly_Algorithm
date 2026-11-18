#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        heapSort(nums, nums.size());

        return nums[k - 1];
    }

    void heapify(vector<int> &nums, int i, int n)
    {
        int currentMinIndex = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && nums[l] < nums[currentMinIndex])
        {
            currentMinIndex = l;
        }
        if (r < n && nums[r] < nums[currentMinIndex])
        {
            currentMinIndex = r;
        }

        if (currentMinIndex != i)
        {
            int nextIndex = currentMinIndex;
            swap(nums[i], nums[currentMinIndex]);

            heapify(nums, nextIndex, n);
        }
    }

    void heapSort(vector<int> &nums, int n)
    {
        int start = (n - 1) / 2;
        for (int i = start; i >= 0; i--)
        {
            heapify(nums, i, n);
        }

        for (int i = n - 1; i > 0; i--)
        {
            swap(nums[i], nums[0]);
            heapify(nums, 0, i);
        }
    }
};

