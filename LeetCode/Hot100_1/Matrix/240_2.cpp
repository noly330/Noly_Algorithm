#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        for(int i =0;i<m;i++){
            auto it = lower_bound(matrix[i].begin(),matrix[i].end(),target);
            if(it != matrix[i].end() && *it == target)
                return true;
        }
        return false;
    }
};
