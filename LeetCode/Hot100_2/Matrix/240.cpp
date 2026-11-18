#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i < m;i++){
            if(target>=matrix[i][0] && target<=matrix[i][n-1]){
                if(binarySearch(matrix[i],target)){
                    return true;
                }
            }
        }

        return false;
    }

    bool binarySearch(vector<int> &a,int target){
        int n = a.size();
        int l = -1;
        int r = n;
        while(l+1<r){
            int mid = l+(r-l)/2;
            if(a[mid] == target){
                return true;
            }
            
            if(a[mid] < target){
                l = mid;
            }
            else{
                r = mid;
            }
        }

        return false;
    }
};