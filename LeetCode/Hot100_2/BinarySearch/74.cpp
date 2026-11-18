#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int col = -1;
        for(int i = 0;i<n;i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                col = i;
                break;;
            }
        }

        if(col == -1)
            return false;
        
        int l =0; int r = m-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(matrix[col][mid] == target){
                return true;
            }
            if(matrix[col][mid]<target){
                l = mid+1;
            }
            else{
                r = mid - 1;
            }
        }

        return matrix[col][l] == target;
    }
};