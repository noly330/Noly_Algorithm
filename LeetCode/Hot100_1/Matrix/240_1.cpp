#include <bits/stdc++.h>
using namespace std;

#include <vector>
using namespace std;

bool binarySearch(const vector<int> &arr, int target)
{
    int n = arr.size();
    int l = 0, r = n - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target) {
            return true;
        }
        else if (arr[mid] > target) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }  
    }
    return false;
}

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        if (m == 0) return false;
        
        int n = matrix[0].size();
        
        for (int i = 0; i < m; i++) {
            if (binarySearch(matrix[i], target)) {
                return true;
            }
        }
        return false;
    }
};