#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp = nums;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int next = (i+k)%n;
            nums[next] = temp[i];
        }
    }
};