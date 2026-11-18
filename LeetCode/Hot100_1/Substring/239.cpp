#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        int n = nums.size();

        for (int i = 0; i < k; i++)
        {
            // pq.emplace(nums[i],i);
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        for (int i = 1; i < n - k + 1; i++)
        {
            pq.push({nums[i+k-1],i+k-1});
            while(pq.top().second < i){
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};