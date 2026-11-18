#include<bits/stdc++.h>
using namespace std;

//TODO:可以优化内存

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> a(n);
        for(int i = 0;i<n;i++){
            int p = (i+k) % n;

            a[p] = nums[i];
        }

        nums = a;
    }
};